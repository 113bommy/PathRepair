#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int n;
int num[MAXN];
int vis[MAXN];
int main() {
  num[0] = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int tmp;
    cin >> tmp;
    vis[tmp]++;
  }
  for (int i = 1; i <= n; i++) cin >> num[i];
  int pos;
  for (int i = n - 1; i >= 0; i++) {
    if (num[i + 1] - num[i] != 1 || num[i] == 0) {
      pos = i + 1;
      break;
    }
  }
  if (num[pos] == 1) {
    int flag = 1;
    for (int i = 1; i < pos; i++) {
      if (num[i] && num[i] - i <= num[n]) {
        flag = 0;
        break;
      }
    }
    if (flag == 1) {
      cout << pos - 1;
      return 0;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (num[i]) ans = max(ans, i - num[i] + 1);
  cout << (ans + n);
}
