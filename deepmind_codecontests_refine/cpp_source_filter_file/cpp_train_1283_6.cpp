#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const double EPS = 1e-10;
int sus[100010][2];
int commit[100010][2];
int sum[2];
int a[100010];
char c[100010];
int main() {
  int n, m;
  cin >> n >> m;
  memset(sus, 0, sizeof(sus));
  memset(sum, 0, sizeof(sum));
  memset(commit, 0, sizeof(commit));
  for (int i = 0; i < n; i++) {
    scanf(" %c%d", &c[i], &a[i]);
    if (c[i] == '-') {
      sum[1]++;
      sus[--a[i]][1]++;
    } else {
      sum[0]++;
      sus[--a[i]][0]++;
    }
  }
  int total = 0;
  for (int i = 0; i < n; i++) {
    if (sus[i][0] + sum[1] - sus[i][1] == m) {
      total++;
      commit[i][0]++;
      commit[i][1]--;
    }
  }
  for (int i = 0; i < n; i++) commit[i][1] += total;
  for (int i = 0; i < n; i++) {
    bool f, g;
    if (c[i] == '+') {
      f = commit[a[i]][0] > 0;
      g = commit[a[i]][1] > 0;
    } else {
      f = commit[a[i]][1] > 0;
      g = commit[a[i]][0] > 0;
    }
    if ((f && g) || (!f && !g))
      cout << "Not defiened" << endl;
    else if (f)
      cout << "Truth" << endl;
    else
      cout << "Lie" << endl;
  }
  return 0;
}
