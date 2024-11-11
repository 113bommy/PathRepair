#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
const int MN=100000;
int N,M,Q,a[MN];
bool done[MN];		//value done?
int its[MN];		//where iterate?
set<int> v2ps[MN];
int top;
bool okalone(int num,int I){
	if(num!=top) return 0;
	for(int it=I;it<Q&&num<M;it++){
		int v=a[it];
		if(done[v]) continue;
		if(v>num) return 0;
		if(a[it]==num){
			num++;
			while(num<M&&done[num]) num++;
		}
	}
	return (num==M);
}
bool solve(){
	cin>>N>>M>>Q;
	if(N==1) return 1;
	rep(i,Q) cin>>a[Q-1-i],a[Q-1-i]--;
	rep(i,Q) v2ps[a[i]].insert(i);
	while(true){
		int I=its[0];
		for(;I<Q;I++){
			if(!done[a[I]]) break;
		}
		if(I==Q){
			return 1;
		}
		int v=a[I];
//		show(I);
//		show(v);

		if(okalone(v,I)) return 1;

		set<int>& st=v2ps[v];
		rep(i,N){
			auto it=st.lower_bound(its[i]);
			if(it==st.end()) return 0;
			its[i]=*it;
			st.erase(it);
		}
		done[v]=1;
		if(top==v){
			while(top<M&&done[top]) top++
		}
	}
	assert(false);
}

int main(){
	if(solve()) puts("Yes");
	else puts("No");
}