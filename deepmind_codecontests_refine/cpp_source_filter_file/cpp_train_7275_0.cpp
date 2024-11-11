#include <bits/stdc++.h>
using namespace std;
double EPS=1e-10;
double add(double a,double b) {
	if(abs(a+b)<EPS*(abs(a)+abs(b))) return 0;
	return a+b;
}
typedef pair<int,int> PI;
typedef pair<double,PI> E;
struct P {
	double x,y;
	P() {}
	P(double x,double y):x(x),y(y) {}
	P operator+(P p) const{
		return P(add(x,p.x),add(y,p.y));	
	}
	P operator-(const P p) const {
		return P(add(x,-p.x),add(y,-p.y));
	}
	P operator*(double d) const{
		return P(x*d,y*d);	
	}
	double dot(const P p) const{
		return add(x*p.x,y*p.y);
	}
	double det(const P p) const{
		return add(x*p.y,-y*p.x);	
	}
};
bool cmp_x(const P& p,const P& q) {
	if(p.x!=q.x) return p.x<q.x;
	return p.y<q.y;
}
vector<P> convex_hull(P* ps,int n) {
	sort(ps,ps+n,cmp_x);
	int k=0;
	vector<P> qs(n*2);
	for(int i=0;i<n;i++) {
		while(k>1 && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) k--;
		qs[k++]=ps[i];
	}
	for(int i=n-2,t=k;i>=0;i--) {
		while(k>t && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) k--;
		qs[k++]=ps[i];
	}
	qs.resize(k-1);
	return qs;
}
double dist(P p,P q) {
	return sqrt((p-q).dot(p-q));	
}
int par[100];
int rank[100];
void init(int n) {
	for(int i=0;i<n;i++) {
		par[i]=i;
		rank[i]=0;
	}
}
int find(int x) {
	if(par[x]==x) {
		return x;
	}else {
		return par[x]=find(par[x]);	
	}
}
void unite(int x,int y) {
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(rank[x]<rank[y]) {
		par[x]=y;	
	}else {
		par[y]=x;
		if(rank[x]==rank[y]) rank[x]++;
	}
}
bool same(int x,int y) {
	return find(x)==find(y);	
}
map<PI,int> idx;
int main() {
	int V,R;
	scanf("%d %d",&V,&R);
	P ps[100],tmp_ps[100];
	for(int i=0;i<V;i++) {
		int x,y;
		scanf("%d %d",&x,&y);
		tmp_ps[i]=ps[i]=P(x,y);
		idx[PI(x,y)]=i;
	}
	vector<P> conv=convex_hull(tmp_ps,V);
	conv.push_back(conv[0]);
	init(V);
	double ans=0;
	for(int i=1;i<conv.size();i++) {
		ans+=dist(conv[i-1],conv[i]);
		unite(idx[PI(conv[i-1].x,conv[i-1].y)],idx[PI(conv[i].x,conv[i].y)]);
	}
	E road[1000];
	for(int i=0;i<R;i++) {
		int s,t;
		scanf("%d %d",&s,&t);s--;t--;
		road[i]=E(dist(ps[s],ps[t]),PI(s,t));
	}
	sort(road,road+R);
	for(int i=0;i<R;i++) {
		double d=road[i].first;
		int s=road[i].second.first;
		int t=road[i].second.second;
		if(same(s,t)) continue;
		unite(s,t);
		ans+=d;
	}
	printf("%.15lf\n",ans);
}
