#include <bits/stdc++.h>
using namespace std;
struct tag {
  int start = -1, end = -1;
};
bool compare(const struct tag& a, const struct tag& b) {
  return (a.end < b.end);
}
int ans[1000004];
int main() {
  struct tag A[50];
  int i, n, k;
  string s;
  cin >> n >> k >> s;
  for (i = 0; i < n; i++) {
    if (A[s[i] - 65].start == -1) A[s[i] - 65].start = i;
    A[s[i] - 65].end = i;
  }
  for (i = 0; i < n; i++) ans[i] = 0;
  for (i = 0; i < 26; i++) {
    if (A[i].start == -1) continue;
    ans[A[i].start] += 1;
    ans[A[i].end + 1] -= 1;
  }
  int XY = 0;
  for (i = 0; i < n; i++) {
    XY = XY + ans[i];
    if (XY > k) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
