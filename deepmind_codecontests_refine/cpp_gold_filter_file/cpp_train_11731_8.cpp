#include <bits/stdc++.h>
using namespace std;
char a[1000006];
int vis[1000006];
map<char, int> dict;
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dict[a[i]]++;
  }
  for (int i = 0; i < k;) {
    for (char ch = 'a'; ch <= 'z'; ch++) {
      if (dict[ch]) {
        for (int j = 1; j <= n; j++) {
          if (a[j] == ch && !vis[j]) {
            vis[j] = 1;
            i++;
            dict[ch]--;
            if (i == k) break;
          }
        }
        break;
      }
      if (i == k) break;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) cout << a[i];
  }
}
