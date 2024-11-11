#include <bits/stdc++.h>
using namespace std;
int a[305], b[305], p, ot1[1000005], ot2[1000005];
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++) {
    int now = a[i], pos;
    for (int j = i; j <= n; j++)
      if (b[j] == now) {
        pos = j;
        break;
      }
    for (int j = pos; j > i; j--)
      ot1[++p] = j - 1, ot2[p] = j, swap(b[j], b[j - 1]);
  }
  cout << p << "\n";
  for (int i = 1; i <= p; i++) cout << ot1[i] << " " << ot2[i] << "\n";
}
