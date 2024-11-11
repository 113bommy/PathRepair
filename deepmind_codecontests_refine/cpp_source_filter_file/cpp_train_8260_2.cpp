#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 * 1000 + 10;
set<int> s;
int a[maxn], n;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int ors = 0;
    s.insert(a[i]);
    for (int j = i - 1; j >= 0; j--) {
      ors |= a[j];
      if ((ors & (~a[i])) == 0) break;
      s.insert(ors | a[i]);
    }
  }
  cout << int(s.size()) << endl;
  return 0;
}
