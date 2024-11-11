#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), p(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    p[a[i] - 1] = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int count = 0;
  int diff = 0;
  for (int i = 0; i + count < n; i++) {
    if (a[i - diff] != b[i]) {
      int pos = p[b[i] - 1];
      count = max(count, n - pos);
      diff++;
    }
  }
  cout << count << endl;
  return 0;
}
