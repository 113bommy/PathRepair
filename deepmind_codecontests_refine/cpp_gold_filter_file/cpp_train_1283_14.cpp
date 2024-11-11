#include <bits/stdc++.h>
using namespace std;
long n, m, rec, ai;
char c;
long ans, i;
long pp[111111];
long mm[111111];
long cur[111111];
bool fix[111111];
long pans, mans;
vector<long> r;
char re[111111];
int main() {
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    scanf("\n%c%d", &c, &ai);
    cur[i] = ai;
    re[i] = c;
    if (c == '+') {
      pp[ai]++;
      pans++;
    }
    if (c == '-') {
      mm[ai]++;
      mans++;
    }
  }
  for (i = 1; i <= n; i++) {
    rec = mans - mm[i] + pp[i];
    if (rec == m) {
      ans++;
      fix[i] = true;
    }
  }
  if (ans == 1) {
    for (i = 1; i <= n; i++) {
      if (re[i] == '-') {
        if (fix[cur[i]] == 0)
          cout << "Truth" << endl;
        else
          cout << "Lie" << endl;
      }
      if (re[i] == '+') {
        if (fix[cur[i]] == 0)
          cout << "Lie" << endl;
        else
          cout << "Truth" << endl;
      }
    }
    return 0;
  }
  for (i = 1; i <= n; i++) {
    if (re[i] == '-') {
      if (fix[cur[i]] == 0)
        cout << "Truth" << endl;
      else
        cout << "Not defined" << endl;
    }
    if (re[i] == '+') {
      if (fix[cur[i]] == 0)
        cout << "Lie" << endl;
      else
        cout << "Not defined" << endl;
    }
  }
  return 0;
  system("D.exe");
}
