#include <bits/stdc++.h>
using namespace std;
const int max_n = 100111, inf = 1000111222;
int cnt[max_n];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i + 1 < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    cnt[a]++;
    cnt[b]++;
  }
  for (int i = 0; i < n; ++i) {
    if (cnt[i] == 2) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
