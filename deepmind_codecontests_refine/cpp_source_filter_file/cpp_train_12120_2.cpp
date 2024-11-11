#include <bits/stdc++.h>
using namespace std;
int num, x, p[1001], n, m, i, j, A[100001], B[100001];
vector<pair<int, int> > a;
bool how(pair<int, int> A, pair<int, int> B) { return A.second < B.second; };
bool give1(int u) {
  if (A[u] == 0) {
    A[u] = a[i].first;
    return 1;
  } else
    return 0;
};
bool give2(int u) {
  if (B[u] == 0) {
    B[u] = a[i].first;
    return 1;
  } else
    return 0;
};
int main() {
  cin >> n >> m;
  for (i = 1; i <= n; i++) cin >> x, p[x]++;
  for (i = 1; i <= m; i++)
    if (p[i] != 0) a.push_back(make_pair(i, p[i]));
  sort(a.begin(), a.end(), how);
  for (i = 0; i < a.size(); i++) {
    int raod = a[i].second;
    for (j = 1; j <= n; j++)
      if (a[i].second && B[j] != 0 && give1(j)) a[i].second--;
    for (j = 1; j <= n; j++)
      if (a[i].second && give1(j)) a[i].second--;
    a[i].second = raod;
    for (j = 1; j <= n; j++)
      if (a[i].second && A[j] != a[i].first && give2(j)) a[i].second--;
    for (j = 1; j <= n; j++)
      if (a[i].second && give2(j)) a[i].second--;
  };
  for (i = 1; i <= n; i++)
    if (A[i] != B[i]) num++;
  cout << num << endl;
  for (i = 1; i <= n; i++) cout << A[i] << " " << B[i] << endl;
  return 0;
}
