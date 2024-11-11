#include <bits/stdc++.h>
using namespace std;
using namespace std;
int t, n, m, sum, ar[100005];
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> ar[i];
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++)
      if (!ar[i])
        b++;
      else
        a++;
    if (a < b) {
      cout << b << endl;
      for (int i = 1; i <= b; i++) cout << 0 << " ";
      cout << endl;
    } else {
      if (a % 2) a--;
      cout << a << endl;
      for (int i = 1; i <= a; i++) cout << 1 << " ";
      cout << endl;
    }
  }
}
