#include <bits/stdc++.h>
using namespace std;
const int nmax = 1000001;
int memo1[nmax];
int memo2[nmax];
int main() {
  int m;
  cin >> m;
  int x1, y1, x2, y2, a1, a2;
  long long h1, h2;
  cin >> h1 >> a1;
  cin >> x1 >> y1;
  cin >> h2 >> a2;
  cin >> x2 >> y2;
  int ans1 = 0, ans2 = 0;
  for (int i = 0; i < m; ++i) {
    if (h1 == a1) {
      break;
    }
    h1 = ((long long)h1 * x1 + y1) % m;
    if (memo1[h1]) {
      cout << "-1\n";
      return 0;
    }
    ++ans1;
    memo1[h1] = 1;
  }
  for (int i = 0; i < m; ++i) {
    if (h2 == a2) {
      break;
    }
    h2 = ((long long)h2 * x2 + y2) % m;
    if (memo2[h2]) {
      cout << "-1\n";
      return 0;
    }
    ++ans2;
    memo2[h2] = 1;
  }
  int l1 = 0, l2 = 0;
  if (ans1 == ans2) {
    cout << ans1 << "\n";
    return 0;
  } else {
    if (ans1 < ans2) {
      for (int i = ans1; i <= ans2; ++i) {
        h1 = ((long long)h1 * x1 + y1) % m;
      }
      if (h1 == a1) {
        cout << ans2 << "\n";
        return 0;
      }
    } else {
      for (int i = ans2; i <= ans1; ++i) {
        h2 = ((long long)h2 * x2 + y2) % m;
      }
      if (h2 == a2) {
        cout << ans1 << "\n";
        return 0;
      }
    }
    h1 = a1;
    memset(memo1, 0, sizeof(memo1));
    memset(memo2, 0, sizeof(memo2));
    for (int i = 0; i < m; ++i) {
      h1 = ((long long)h1 * x1 + y1) % m;
      if (memo1[h1]) {
        cout << "-1\n";
        return 0;
      }
      ++l1;
      memo1[h1] = 1;
      if (h1 == a1) {
        break;
      }
    }
    h2 = a2;
    for (int i = 0; i < m; ++i) {
      h2 = ((long long)h2 * x2 + y2) % m;
      if (memo2[h2]) {
        cout << "-1\n";
        return 0;
      }
      ++l2;
      memo2[h2] = 1;
      if (h2 == a2) {
        break;
      }
    }
  }
  if (ans1 < ans2) {
    swap(ans1, ans2);
    swap(l1, l2);
  }
  int nr_cycles = 0;
  for (;;) {
    long long dist = (long long)nr_cycles * l1 + ans1 - ans2;
    if (dist % l2 == 0) {
      break;
    }
    ++nr_cycles;
    if (nr_cycles > 10000000) {
      cout << "-1\n";
      return 0;
    }
  }
  long long ans = (long long)nr_cycles * l1 + ans1;
  cout << ans << "\n";
  return 0;
}
