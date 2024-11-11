#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
//#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
typedef complex<double> pt;
#define EPS 1e-9
#define X real()
#define Y imag()
pt c[105]; double r[105];
vector<P>edge[105];
int n,m;
bool eq(double a,double b){
  return (-EPS < a-b && a-b < EPS);
}
bool cmp(const P& a,const P& b){
    assert(a.sc == b.sc);
    double A = atan2(c[a.fi].Y-c[a.sc].Y,c[a.fi].X-c[a.sc].X);
    double B = atan2(c[b.fi].Y-c[b.sc].Y,c[b.fi].X-c[b.sc].X);
    return A < B;
}
int ran[105][105];
vector<pt>convex[105][105];
bool used[105][105];
void dfs(int cur,int pre,int gen,int num){
    if(cur == gen) return 1;
    convex[gen][num].pb(c[cur]);
    f = (ran[cur][pre]+1)%edge[cur].size();
    dfs(edge[cur][f].fi,cur,gen,num); return ;
}
 
double dot(pt a,pt b){
    return (conj(a)*b).X;
}
double cross(pt a,pt b){
    return (conj(a)*b).Y;
}
int ccw(pt a,pt b,pt c){
    b -= a; c -= a;
    if(cross(b,c) > EPS) return 1; // counter clockwise
    if(cross(b,c) < -EPS) return -1; // clockwise
    if(dot(b,c) < -EPS) return 2; //c-a-b
    if(norm(b) < norm(c)) return -2; //a-b-c
    return 0; //a-c-b
}
 
 
pt crossPoint(pt a,pt b,pt c,pt d){
    double A = cross(b-a,d-c);
    double B = cross(b-a,b-c);
    if( fabs(A) < EPS && fabs(B) < EPS ) return c;
    else if(fabs(A) >= EPS ) return c+B/A*(d-c);
    else pt(1e9,1e9);
}
 
bool on_segment(pair<pt,pt> a,pt p){
  return eq(abs(a.first-a.second)-abs(a.first-p)-abs(a.second-p),0);
}
 
 
double dist_lp(pt a,pt b,pt c){
    //senbun a-b to c no dist
    if(dot(a-b,c-b) <= 0.0) return abs(c-b);
    if(dot(b-a,c-a) <= 0.0) return abs(c-a);
    return abs(cross(b-a,c-a)) / abs(b-a);
}
 
bool intersect(pt a,pt b,pt c,pt d){
    return (ccw(a,b,c)*ccw(a,b,d) <= 0 && ccw(c,d,a)*ccw(c,d,b) <= 0);
}
 
bool contain_point(vector<pt>ps,pt p){
    double sum = 0;
    //arg no sum wo keisan
    for(int i=0;i<ps.size();i++){
        if(on_segment(mp(ps[i],ps[ (i+1)%ps.size() ]),p)) return 1;
        sum += arg( (ps[ (i+1)%ps.size() ]-p) / (ps[i]-p) );
    }
    return (abs(sum) > 1);
}
 
int main(){
    while(1){
        scanf("%d%d",&n,&m); if(n == 0 && m == 0) return 0;
        memset(used,0,sizeof(used));
        for(int i=1;i<=n;i++){
            double x,y;
            scanf("%lf%lf%lf",&x,&y,&r[i]);
            c[i] = pt(x,y);
        }
        for(int i=0;i<105;i++) edge[i].clear();
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(abs(c[i]-c[j])-EPS > r[i]+r[j]) continue;
            //  cout << abs(c[i]-c[j]) << max(r[i],r[j])-min(r[i],r[j]) << endl;
                if(abs(c[i]-c[j]) < max(r[i],r[j])-min(r[i],r[j])-EPS) continue;
                edge[i].pb(mp(j,i));
                edge[j].pb(mp(i,j));//cout <<i<<" " << j<<endl;
            }
        }
        //right(left?)-hand-method
        for(int i=1;i<=n;i++){
            sort(edge[i].begin(),edge[i].end(),cmp);
            for(int j=0;j<edge[i].size();j++){
                ran[i][edge[i][j].fi] = j;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<edge[i].size();j++){
                convex[i][j].clear();
                convex[i][j].pb(c[i]);
                dfs(edge[i][j].fi,i,i,j);
                //for(int k=0;k<convex[i][j].size();k++) cout << convex[i][j][k] << " "; puts("");
            }
        }
        for(int i=1;i<=m;i++){
            pt p1,p2;
            double xa,xb,xc,xd;
            scanf("%lf%lf%lf%lf",&xa,&xb,&xc,&xd);
            p1 = pt(xa,xb); p2 = pt(xc,xd);
            int cnt = 0;
            bool ok = 1;
            for(int j=1;j<=n;j++){
                bool b1=0,b2=0;
                if(abs(c[j]-p1) < r[j]+EPS) b1 = 1;
                if(abs(c[j]-p2) < r[j]+EPS) b2 = 1;
                if(!b1 && b2){
                    ok = 0; goto bad;
                }
                if(b1 && !b2){
                    ok = 0; goto bad;
                }
                cnt+=b1;
            }
            if(cnt) goto bad;
            for(int j=1;j<=n;j++){
                for(int w=0;w<edge[j].size();w++){
                    if(convex[j][w].size() <= 2) continue;
                    if((contain_point(convex[j][w],p1) ^ contain_point(convex[j][w],p2))){
                        ok = 0; goto bad;
                    }
                }
            }
            bad:;
            printf(ok?"YES%c":"NO%c",(i==m?'\n':' '));
        }
        //puts("");
    }
}