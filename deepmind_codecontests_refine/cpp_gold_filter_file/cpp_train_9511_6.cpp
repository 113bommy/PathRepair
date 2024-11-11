#include <bits/stdc++.h>
using namespace std;
vector<int> v[1010];
int n, m, x, minv, choose, cnt, tot, a[1010], must[1010], num[1010];
double C[1010][1010], f[1010][1010], tmp;
bool prob[1010];
int main() {
  C[0][0] = 1;
  for (int i = 1; i <= 1000; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
  }
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> num[i];
    for (int j = 1; j <= num[i]; j++) {
      cin >> x;
      v[i].push_back(x);
      a[++tot] = x;
    }
  }
  sort(a + 1, a + 1 + tot);
  minv = a[tot - n];
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < v[i].size(); j++)
      if (v[i][j] > minv)
        cnt++, must[i]++;
      else if (v[i][j] == minv)
        prob[i] = true;
    choose += prob[i];
  }
  f[0][0] = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= n - cnt; j++)
      if (!prob[i])
        f[i][j] = f[i - 1][j] / C[num[i]][must[i]];
      else {
        tmp = (double)(n - cnt - j) / choose;
        f[i][j] += f[i - 1][j] / C[num[i]][must[i]] * (1 - tmp);
        f[i][j + 1] += f[i - 1][j] / C[num[i]][must[i] + 1] * tmp;
      }
    choose -= prob[i];
  }
  cout << fixed << setprecision(10) << f[m][n - cnt] << endl;
}
