#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];
    int i = 0, j = 0, s1 = 0, s2 = 0;
    int count = -1;
    while ((i < n) and (j < m)) {
      if (s1 < s2) {
        s1 += a[i];
        i++;
      } else if (s1 > s2) {
        s2 += b[j];
        j++;
      } else {
        count++;
        s1 = a[i];
        s2 = b[j];
        i++, j++;
      }
    }
    count++;
    cout << count << "\n";
  }
  return 0;
}
