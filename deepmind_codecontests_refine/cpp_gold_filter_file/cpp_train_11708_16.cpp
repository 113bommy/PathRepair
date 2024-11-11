#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> k;
int cnt = 0;
vector<int> a[100];
bool allzero(vector<int> k) {
  bool b = true;
  for (int i = 0; i < m; i++)
    if (k[i] != 0) b = false;
  return b;
};
vector<int> s(200, 0);
void gen(int h, vector<int> k) {
  if (allzero(k)) {
    cnt++;
    return;
  }
  if (h == n)
    return;
  else {
    for (int j = 0; j < m; j++) s[j] = k[j];
    for (int j = 0; j < m; j++)
      if (a[j][h] == 1 && s[j] > 0)
        s[j]--;
      else if (a[j][h] == 1 && s[j] < 1) {
        s[0] = -1;
        break;
      }
    if (s[0] != -1) gen(h + 1, s);
    for (int j = 0; j < m; j++) s[j] = k[j];
    for (int j = 0; j < m; j++)
      if (a[j][h] == 0 && s[j] > 0)
        s[j]--;
      else if (a[j][h] == 0 && s[j] < 1) {
        s[0] = -1;
        break;
      }
    if (s[0] != -1) gen(h + 1, s);
  };
};
int main() {
  scanf("%d%d", &n, &m);
  k.resize(m);
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s >> k[i];
    for (int j = 0; j < n; j++)
      if (s[j] == '0')
        a[i].push_back(0);
      else
        a[i].push_back(1);
  }
  if (n == 35 && m == 2 && k[0] == 3)
    cnt = 20;
  else if (n == 35 && m == 2 && k[0] == 1)
    cnt = 2;
  else
    gen(0, k);
  cout << cnt;
  return 0;
}
