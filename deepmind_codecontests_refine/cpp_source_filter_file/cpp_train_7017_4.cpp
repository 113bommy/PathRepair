#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
long long ar[maxn];
int main() {
  long long n, m;
  cin >> n >> m;
  long long a, b, c;
  cin >> a >> b >> c;
  ar[a] = 1, ar[b] = 2, ar[c] = 3;
  for (int i = 1; i < m; ++i) {
    cin >> a >> b >> c;
    if (!ar[a] and !ar[b] and !ar[c])
      ar[a] = 1, ar[b] = 2, ar[c] = 3;
    else {
      if (ar[a]) {
        if (ar[a] == 1)
          ar[b] = 2, ar[c] = 3;
        else if (ar[a] == 2)
          ar[b] = 1, ar[c] = 3;
        else
          ar[b] = 1, ar[c] = 3;
      } else if (ar[b]) {
        if (ar[b] == 1)
          ar[a] = 2, ar[c] = 3;
        else if (ar[b] == 2)
          ar[a] = 1, ar[c] = 3;
        else
          ar[a] = 1, ar[c] = 3;
      } else if (ar[c]) {
        if (ar[c] == 1)
          ar[a] = 2, ar[b] = 3;
        else if (ar[c] == 2)
          ar[a] = 1, ar[b] = 3;
        else
          ar[a] = 1, ar[b] = 3;
      }
    }
  }
  for (int i = 1; i < n + 1; ++i) cout << ar[i] << " ";
  return 0;
}
