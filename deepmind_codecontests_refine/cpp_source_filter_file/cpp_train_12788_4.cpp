#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
#define rep(i, n) for(ll i = 0;i < n;i++)

int main() {
  cin.tie(0); ios::sync_with_stdio(false);

  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;

  int ans_s = 0;
  int ans_w = f;
  rep(a, 31) rep(b, 31) rep(c, 101) rep(d, 101) {
    int w = 100*A*a+100*B*b;
    int s = C*c+D*d;
    if (w == 0 || s*100 > E*w || s+w > F) continue;
    if (s*(ans_s+ans_w) > ans_s*(s+w)) {
      ans_s = s;
      ans_w = w;
    }
  }

  cout << ans_s+ans_w << " " << ans_s << endl;
}
