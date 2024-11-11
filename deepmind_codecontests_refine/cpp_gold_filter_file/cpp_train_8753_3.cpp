#include <bits/stdc++.h>
using namespace std;
vector<long long> vc;
int main() {
  long long n, k, s, i, j, hi, d, cur, m;
  scanf("%lld", &n);
  scanf("%lld", &k);
  scanf("%lld", &s);
  m = k;
  hi = (n - 1) * k;
  if (k > s || hi < s) {
    printf("NO\n");
    return 0;
  }
  cur = 1;
  cout << "YES" << endl;
  for (i = 1; i <= k; i++) {
    if (s == m) {
      if (cur == n) {
        vc.push_back(n - 1);
        cur = n - 1;
      } else if (cur == 1) {
        vc.push_back(2);
        cur = 2;
      } else {
        vc.push_back(cur + 1);
        cur++;
      }
      continue;
      s--;
      m--;
    }
    d = (s - m + 1);
    if (d >= n - 1) {
      if (cur == 1) {
        vc.push_back(n);
        cur = n;
      } else {
        vc.push_back(1);
        cur = 1;
      }
      s -= (n - 1);
      m--;
    } else {
      if (cur == 1) {
        vc.push_back(d + 1);
        cur = d + 1;
      } else {
        vc.push_back(n - d);
        cur = (n - d);
      }
      s -= d;
      m--;
    }
  }
  for (i = 0; i < k; i++) cout << vc[i] << " ";
  cout << endl;
}
