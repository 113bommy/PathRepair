#include <bits/stdc++.h>
using namespace std;
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 2147483600

long solve(){
  int n;
  cin>>n;
  long ret=0;
  vector<long> h(n+1), a(n+1), d(n+1), s(n+1), t(n+1);
  rep(i,n+1) cin>>h[i]>>a[i]>>d[i]>>s[i];

  repl(i,1,n+1){
    long tmp = a[0]-d[i];
    if(tmp<0){
      if(a[i]>d[0]) return -1;
      else tmp=1;
    }
    t[i] = (h[i]+tmp-1)/tmp;
  }

  // ?????´?????? ????????¬??????????????????
  repl(i,1,n+1)if(s[0]>s[i]){
    h[0] += max(a[i]-d[0], 0L);
    ret -= max(a[i]-d[0], 0L);
  }

  vector<int> vec(n);
  rep(i,n) vec[i]=i+1;

  sort(all(vec), [&](int i, int j){
    long ia = max(a[i]-d[0],0L);
    long ja = max(a[j]-d[0],0L);
    return ia*t[j] > ja*t[i];
  });

  long acctime = 0;
  rep(i,n){
    int id = vec[i];
    acctime += t[id];
    h[0] -= max(a[id]-d[0],0L) * acctime;
    ret += max(a[id]-d[0],0L) * acctime;
    if(h[0]<=0) return -1;
  }

  else return ret;
}

int main(){
  cout<<solve()<<endl;

  return 0;
}