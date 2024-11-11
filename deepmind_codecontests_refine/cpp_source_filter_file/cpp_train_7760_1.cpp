#include <bits/stdc++.h>
using namespace std;
int n, res = 999999, dem = 0;
int inddem[10001], ind[10001];
bool bun = false;
string s = "";
int main() {
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (inddem[s[i]] == 0) {
      dem++;
      inddem[s[i]] = 1;
    }
  }
  int j = 0;
  int i = 0;
  if (dem == 0) {
    cout << 1;
    return 0;
  }
  while (i < n && j < n) {
    if (ind[s[j]] == 0) {
      dem--;
    }
    if (bun == false) ind[s[j]]++;
    if (dem == 0) {
      res = min(res, j - i + 1);
      ind[s[i]]--;
      if (ind[s[i]] == 0) dem++;
      bun = true;
      i++;
      continue;
    }
    bun = false;
    j++;
  }
  cout << res;
}
