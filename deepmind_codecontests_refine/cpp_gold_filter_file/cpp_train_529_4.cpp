#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5 + 5;
struct custmer {
  int t;
  int l;
} b[nmax];
bool cmp(struct custmer aa, struct custmer bb) { return aa.t < bb.t; }
int main() {
  int n, L, a;
  cin >> n >> L >> a;
  if (n == 0) {
    cout << L / a << endl;
  } else {
    for (int i = 0; i < n; i++) {
      cin >> b[i].t >> b[i].l;
    }
    sort(b, b + n, cmp);
    long long finsh;
    int sum = b[0].t / a;
    for (int i = 1; i < n; i++) {
      sum += (b[i].t - b[i - 1].t - b[i - 1].l) / a;
    }
    sum += (L - (b[n - 1].t + b[n - 1].l)) / a;
    cout << sum << endl;
  }
  return 0;
}
