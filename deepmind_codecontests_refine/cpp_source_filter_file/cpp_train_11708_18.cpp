#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, m, kq, c[N];
string z[N], y;
bool s[N][N], x[N];
set<string> ans;
bool check(bool x[], int pos) {
  long long num = 0;
  for (long long i = 0; i < n; i++) {
    if (x[i] == s[pos][i]) num++;
  }
  if (num == c[pos]) return true;
  return false;
}
int res;
void attempt(int i, int nmatch) {
  if (i == n + 1) {
    if (nmatch != c[1]) return;
    for (int k = 1; k <= m; k++) {
      if (!check(x, k)) return;
    }
    string temp = "";
    for (long long i = 0; i < n; i++) temp = temp + char(x[i] + 48);
    ans.insert(temp);
    return;
  }
  x[i] = 1 - s[1][i];
  attempt(i + 1, nmatch);
  if (nmatch < c[1]) {
    x[i] = s[1][i];
    attempt(i + 1, nmatch + 1);
  }
}
void convert() {
  for (long long i = 1; i <= m; i++) {
    string temp = z[i];
    for (long long j = 0; j < n; j++) {
      if (temp[j] == '0')
        s[i][j] = 0;
      else
        s[i][j] = 1;
    }
  }
}
int main() {
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    cin >> z[i] >> c[i];
  }
  convert();
  attempt(0, 0);
  cout << ans.size() << "\n";
}
