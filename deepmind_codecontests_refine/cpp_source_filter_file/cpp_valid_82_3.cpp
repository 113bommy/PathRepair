#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const unsigned gen_seed =
    std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);
std::vector<int> pref;
void go(int l, int r) {
  int dif = pref[r] - pref[l - 1];
  int l1 = l;
  int r1 = r;
  while (r1 - l1 > 1) {
    int m1 = (r1 + l1) / 2;
    if (abs(pref[m1] - pref[l - 1]) < abs(pref[m1] - pref[l - 1])) {
      l1 = m1;
    } else
      r1 = m1;
  }
  printf("%d\n", r1);
}
int main() {
  int t;
  scanf("%d", &t);
  char c[300500];
  while (t--) {
    int n, q;
    scanf("%d %d\n", &n, &q);
    scanf("%s", c);
    int cur = 0;
    int tot = 0;
    pref.clear();
    int sg = 1;
    pref.push_back(0);
    for (int i = 0; i < n; i++) {
      if (c[i] == '+')
        tot += sg;
      else
        tot -= sg;
      sg = -sg;
      pref.push_back(tot);
    }
    while (q--) {
      int l, r;
      scanf("%d %d", &l, &r);
      int dif = pref[r] - pref[l - 1];
      if (dif == 0)
        printf("0\n");
      else if (dif % 2 == 0) {
        printf("2\n");
        printf("%d ", l);
        go(++l, r);
      } else {
        printf("1\n");
        go(l, r);
      }
    }
  }
}
