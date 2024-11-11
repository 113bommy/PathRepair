#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;
typedef long double ld;

const ld pi = acos((ld)-1.0);
const ld eps = 1e-6;

ld solve(vector<ld> r, int n) {
  ld mx_area = 0.0;
  do {
    ld mn_prod = 1e+8;
    REP(i,n) {
      mn_prod = min(mn_prod, r[i]*r[(i+1)%n]);
    }
    ld la = -mn_prod, ra = mn_prod;
    REP(i,100) {
      ld mid = (la + ra) / 2.0;
      ld sum_theta = 0.0;
      REP(j,n) {
        sum_theta += acos(mid/(r[j]*r[(j+1)%n]));
      }
      if (sum_theta < 2*pi) ra = mid;
      else la = mid;
    }
    ld lambda = la;
    ld area = 0.0;
    ld sum_theta = 0.0;
    REP(i,n) {
      ld theta = acos(lambda / (r[i] * r[(i+1)%n]));
      sum_theta += theta;
      area += 0.5 * r[i] * r[(i+1)%n] * sin(theta);
    }
    if(abs(sum_theta - 2*pi) > eps) continue;
    mx_area = max(mx_area, area);
  } while(next_permutation(begin(r),end(r)));
  return mx_area;
}

int main() {
  int n;
  cin>>n;
  vector<ld> r(n);
  REP(i,n) cin>>r[i];
  sort(begin(r),end(r));
  ld mx_area = 0.0;
  REP(i,1<<(n-1)) {
    bitset<7> bs(i);
    vector<ld> subr;
    if (bs.count() < 2) continue;
    REP(j,n-1) {
      if(bs[j]) subr.push_back(r[j]);
    }
    subr.push_back(r.back());
    mx_area = max(mx_area, solve(subr, subr.size()));
  }
  cout<<setprecision(10)<<fixed<<mx_area<<endl;
  return 0;
}