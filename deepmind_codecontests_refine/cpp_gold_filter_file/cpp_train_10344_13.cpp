#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int pos[100001];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  int m;
  cin >> m;
  long long v = 0, p = 0;
  int b[m];
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < m; i++) {
    int x = b[i];
    v += pos[x] + 1;
    p += n - pos[x];
  }
  cout << v << " " << p << endl;
}
