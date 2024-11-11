#include <bits/stdc++.h>
using namespace std;
template <typename X>
inline X sqr(const X& a) {
  return a * a;
}
int nxt() {
  int x;
  cin >> x;
  return x;
}
int main() {
  int n = nxt();
  vector<int> a(n + 1);
  generate(1 + a.begin(), a.end(), nxt);
  for (int i = int(1); i < int(n + 1); ++i)
    for (int j = int(1); j < int(n + 1); ++j)
      if (i != j)
        for (int k = int(j + 1); k < int(n + 1); ++k)
          if (i != k && j != k)
            if (a[i] == a[j] + a[k]) {
              cout << i << ' ' << j << ' ' << k << '\n';
              return 0;
            }
  cout << -1 << '\n';
  return 0;
}
