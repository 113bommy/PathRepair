#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
string IntToString(long long a) {
  char x[100];
  sprintf(x, "%lld", a);
  string s = x;
  return s;
}
long long StringToInt(string a) {
  char x[100];
  long long res;
  strcpy(x, a.c_str());
  sscanf(x, "%lld", &res);
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, h;
  cin >> n >> m >> h;
  int a[m];
  for (int i = 0; i < m; i++) cin >> a[i];
  int b[n];
  for (int i = 0; i < n; i++) cin >> b[i];
  int arr[n][m], ans[m][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 1) arr[i][j] = min(a[j], b[i]);
      cout << arr[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}
