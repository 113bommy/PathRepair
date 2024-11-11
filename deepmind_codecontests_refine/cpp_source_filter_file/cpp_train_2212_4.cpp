#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int e, o = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] & 1)
        o++;
      else
        e++;
    }
    if (e % 2 == 0 && o % 2 == 0)
      cout << "YES\n";
    else {
      int f = 0;
      for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
          if (abs(a[i] - a[j]) == 1) f = 1;
      if (f)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
}
