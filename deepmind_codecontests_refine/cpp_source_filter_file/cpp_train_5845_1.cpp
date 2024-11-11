#include <bits/stdc++.h>
using namespace std;
int read() {
  char x = getchar();
  int ans = 0;
  while (!isdigit(x)) x = getchar();
  while (isdigit(x)) ans = ans * 10 + x - '0', x = getchar();
  return ans;
}
int n, m, h[1000005], a[1000005];
int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; i++) h[i] = read();
  int tot = 0;
  vector<int> V;
  V.push_back(0);
  V.push_back(n);
  for (int i = 1; i < m; i++) {
    tot += h[i];
    V.push_back(tot % n);
  }
  sort(V.begin(), V.end());
  vector<int> ans;
  int tmp = (tot + h[m]) / n;
  if ((tot + h[m]) % n) tmp++;
  cout << tmp << endl;
  for (int i = 1; i < V.size(); i++) ans.push_back(V[i] - V[i - 1]);
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
  puts("");
  int pos = 0;
  for (int i = 1; i <= m; i++) {
    while (h[i] > 0) {
      h[i] -= ans[pos];
      pos++;
      cout << i << ' ';
      if (pos == ans.size()) {
        puts("");
        pos = 0;
      }
    }
  }
  while (pos < ans.size()) cout << m << ' ', pos++;
}
