#include <bits/stdc++.h>
using namespace std;
long long a[3];
string matrix[1010][1010];
long long rc[2010];
int main() {
  long long n, m;
  cin >> n >> m;
  memset(a, 0, sizeof(a));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      string s;
      cin >> s;
      a[s[0] - '0' + a[1] - '0']++;
    }
  }
  memset(rc, 0, sizeof(rc));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (a[2] > 0 && rc[j] < n) {
        matrix[rc[j]][j] = "11";
        a[2]--;
        rc[j]++;
      } else if (a[1] > 0 && rc[j] < n) {
        matrix[rc[j]][j] = "10";
        rc[j]++;
        a[1]--;
        if (a[1] > 0 && rc[j] < n) {
          matrix[rc[j]][j] = "01";
          rc[j]++;
          a[1]--;
        }
      } else if (a[0] > 0 && rc[j] < n) {
        matrix[rc[j]][j] = "00";
        rc[j]++;
        a[0]--;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << matrix[i][j] << " ";
    cout << endl;
  }
  return 0;
}
