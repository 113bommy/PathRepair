#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[512][512], b[512][512];
bool NO = 0;
vector<int> f, s;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> b[i][j];
  for (int i = 0; i < n; i++) {
    int currbr = 0;
    for (int j = 0; j < m; j++) currbr += a[i][j];
    f.push_back(currbr);
  }
  for (int j = 0; j < m; j++) {
    int currbr = 0;
    for (int i = 0; i < n; i++) currbr += a[i][j];
    s.push_back(currbr);
  }
  for (int i = 0; i < n; i++) {
    int currbr = 0;
    for (int j = 0; j < m; j++) currbr += b[i][j];
    if (f[i] % 2 != currbr % 2) {
      NO = 1;
      break;
    }
  }
  for (int j = 0; j < m; j++) {
    int currbr = 0;
    for (int i = 0; i < n; i++) currbr += b[i][j];
    if (s[j] % 2 != currbr % 2) {
      NO = 1;
      break;
    }
  }
  if (NO)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  return 0;
}
