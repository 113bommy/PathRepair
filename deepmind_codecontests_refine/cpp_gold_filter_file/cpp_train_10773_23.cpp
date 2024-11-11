#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 30;
const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-15;
const int MaxN = 2600;
int n;
int d[MaxN];
char s[MaxN];
long long e[MaxN][MaxN];
long long answer;
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  string second;
  cin >> second;
  for (int i = 0; i < second.length(); i++) {
    if ('0' <= second[i] && second[i] <= '9') {
      d[n++] = second[i] - '0';
    } else {
      s[n - 1] = second[i];
    }
  }
  for (int i = 0; i < n; i++) e[i][i] = d[i];
  for (int l = 2; l <= n; l++)
    for (int i = 0; i + l - 1 < n; i++) {
      int j = i + l - 1;
      int k = i;
      long long u = d[i];
      while (k < j && s[k] == '*') u = u * d[++k];
      e[i][j] = u + e[k + 1][j];
    }
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++) {
      long long u = e[i][j];
      int left = i - 1;
      while (left >= 0 && s[left] == '*') u = u * d[left--];
      int right = j;
      while (right < n - 1 && s[right] == '*') u = u * d[++right];
      if (left != -1) u = u + e[0][left];
      if (right != n - 1) u = u + e[right + 1][n - 1];
      answer = max(answer, u);
    }
  cout << answer << endl;
  return 0;
}
