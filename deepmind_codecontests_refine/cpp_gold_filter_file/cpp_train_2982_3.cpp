#include <bits/stdc++.h>
using namespace std;
int a[2 * (int)1e5];
vector<int> s;
int main() {
  int n, k, i;
  cin >> n >> k;
  for (i = 0; i < k; i++) {
    scanf("%d", &a[i]);
  }
  i = 0;
  int o = 1;
  while (i < k) {
    while (!s.empty() && s[s.size() - 1] == o) {
      s.pop_back();
      o++;
    }
    s.push_back(a[i++]);
  }
  while (!s.empty() && s[s.size() - 1] == o) {
    s.pop_back();
    o++;
  }
  int j = s.size() - 1;
  if (!s.empty())
    for (j--; j >= 0; j--) {
      if (s[j] < s[j + 1]) {
        cout << -1;
        return 0;
      }
    }
  int to, go;
  while (!s.empty()) {
    to = s[s.size() - 1] - 1;
    go = to;
    while (to >= o) {
      a[i++] = to--;
    }
    o = go + 2;
    s.pop_back();
  }
  to = n;
  while (to >= o) {
    a[i++] = to--;
  }
  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
}
