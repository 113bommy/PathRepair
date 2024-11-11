#include <bits/stdc++.h>
using namespace std;
long long ans;
void chk(vector<long long> r, vector<long long> b, vector<long long> g) {
  for (auto k : r) {
    auto pos1 = upper_bound(b.begin(), b.end(), k);
    auto pos2 = upper_bound(g.begin(), g.end(), k);
    if (pos1 == b.end() || pos2 == g.begin()) continue;
    pos2--;
    ans = min(ans, (k - *pos1) * (k - *pos1) + (k - *pos2) * (k - *pos2) +
                       (*pos1 - *pos2) * (*pos1 - *pos2));
  }
}
void slv() {
  long long a, nr, nb, ng;
  scanf("%lld %lld %lld", &nr, &nb, &ng);
  vector<long long> r, b, g;
  for (long long i = 0; i < nr; i++) {
    scanf("%lld", &a);
    r.push_back(a);
  }
  for (long long i = 0; i < nb; i++) {
    scanf("%lld", &a);
    b.push_back(a);
  }
  for (long long i = 0; i < ng; i++) {
    scanf("%lld", &a);
    g.push_back(a);
  }
  sort(r.begin(), r.end());
  sort(b.begin(), b.end());
  sort(g.begin(), g.end());
  ans = 9e18;
  chk(r, b, g);
  chk(r, g, b);
  chk(b, r, g);
  chk(b, g, r);
  chk(g, b, r);
  chk(g, r, b);
  cout << ans << endl;
}
int main() {
  long long t;
  scanf("%lld", &t);
  while (t--) {
    slv();
  }
  return 0;
}
