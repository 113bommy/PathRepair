//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <queue>
 
using namespace std;
 
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
 
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
 
//constant
//--------------------------------------------
const double eps = 1e-10;
const double PI  = acos(-1.0);
const double INF = 1e9;
 
struct P{
  double x;
  double y;
 
  P(){
    x=INF,y=INF;
  }
 
  P(const double &s , const double &e)
  { x=s; y=e;}
 
  P operator - (const P &t) const
  { return P(x-t.x , y-t.y); }
 
  P operator + (const P &t) const
  { return P(x+t.x , y+t.y); }
 
  P operator * (const double &d) const
  { return P(x*d , y*d); }
};
double dis(P t){
  return sqrt(t.x*t.x+t.y*t.y);
}
 
P unit_vector(P t){
  double u=fabs(dis(t));
  return P(t.x/u , t.y/u);
}
P rotate(P t , P p , double r){
  //double r=radians(angle);
  double ta=cos(r)*(t.x-p.x)-sin(r)*(t.y-p.y)+p.x;
  double tb=sin(r)*(t.x-p.x)+cos(r)*(t.y-p.y)+p.y;
  return P(ta , tb);
}
 
void interpoint_cc(P a , double ra , P b , double rb , P ans[]){
  double di=fabs(dis(a-b));
  if(di > ra+rb || di < fabs(ra-rb)) return;
  double t=(ra*ra-rb*rb+di*di)/(di+di);
  double rd=acos(t/ra);
 
  P dv=unit_vector(b-a);
  P g1=rotate(dv , P(0,0) , rd);
  P g2=rotate(dv , P(0,0) , -rd);
  ans[0]=a+g1*ra;
  ans[1]=a+g2*ra;
}
 
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
 
  int N;
  while(cin>>N,N){
    vector<P> p(N);
    vector<double> ls(N);
    REP(i,N) cin >> p[i].x >> p[i].y >> ls[i];
 
    double lb = 0, ub = 300;
    REP(loop,100){
      double h = (lb + ub) / 2.;
      bool ok = true;
      REP(i,N) if(ls[i] < h) ok = false;
 
      if(ok){
        ok = false;
        vector<double> ri(N);
        REP(i,N) ri[i] = sqrt(ls[i]*ls[i] - h*h);
        vector<P> chk;
        REP(i,N){
          REP(j,N){
            if(dis(p[i]-p[j]) > ri[i]+ri[j] || dis(p[i]-p[j]) < fabs(ri[i]-ri[j])) continue;
            P icp[2];
            interpoint_cc(p[i], ri[i], p[j], ri[j], icp);
            chk.PB(icp[0]);
            chk.PB(icp[1]);
          }
          chk.PB(p[i]);
        }
        for(auto& pp: chk){
          int cnt = 0;
          REP(k,N){
            if(dis(p[k]-pp) <= ri[k]+EPS)
              ++cnt;
          }
          if(cnt == N) ok = true;
        }
      }
 
      if(ok) lb = h;
      else ub = h;
    }
    cout << fixed << setprecision(9) << lb << endl;
  }
   
  return 0;
}