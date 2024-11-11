#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  string s;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    int a[n], bg = 8 * n, sm = -n;
    if (s[0] == '>')
      a[0] = INT_MAX;
    else
      a[0] = sm + 1;
    for (int i = 0; i < n - 1;) {
      while (i < n - 1 and s[i] == '>') {
        a[i + 1] = sm--;
        i++;
      }
      int st = i + 1;
      while (i < n - 1 and s[i] == '<') {
        a[i + 1] = bg--;
        i++;
      }
      reverse(a + st, a + i + 2);
    }
    int id[n];
    for (int i = 0; i < n; i++) id[i] = i;
    int st = 1;
    sort(id, id + n, [&a](int p, int n) { return a[p] < a[n]; });
    for (int i = 0; i < n; i++) a[id[i]] = st++;
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    puts("");
    bg = 8 * n, sm = -n;
    if (s[0] == '>')
      a[0] = bg - 1;
    else
      a[0] = sm + 1;
    for (int i = 0; i < n - 1;) {
      while (i < n - 1 and s[i] == '<') {
        a[i + 1] = bg++;
        i++;
      }
      int st = i + 1;
      while (i < n - 1 and s[i] == '>') {
        a[i + 1] = sm++;
        i++;
      }
      reverse(a + st, a + i + 2);
    }
    for (int i = 0; i < n; i++) id[i] = i;
    st = 1;
    sort(id, id + n, [&a](int p, int n) { return a[p] < a[n]; });
    for (int i = 0; i < n; i++) a[id[i]] = st++;
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    puts("");
  }
}
