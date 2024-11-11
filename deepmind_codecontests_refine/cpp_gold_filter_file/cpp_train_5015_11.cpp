#include <bits/stdc++.h>
using namespace std;
string gs = "G";
string bs = "B";
string rs = "R";
void answer();
int main() {
  for (long long i = 1; i < 200009; i++) {
    if (i % 3 == 1)
      rs.append("G");
    else if (i % 3 == 2)
      rs.append("B");
    else
      rs.append("R");
  }
  bs.append(rs);
  gs.append(bs);
  long long t;
  cin >> t;
  while (t--) {
    answer();
  }
  return 0;
}
void answer() {
  long long n, k;
  string s;
  cin >> n >> k;
  cin >> s;
  long long errors = k;
  long long e1, e2, e3;
  e1 = e2 = e3 = 0;
  for (long long i = 0; i < k; i++)
    if (rs[i] != s[i]) e1++;
  errors = min(errors, e1);
  for (long long i = k; i < n; i++) {
    if (rs[i] != s[i]) e1++;
    if (rs[i - k] != s[i - k]) e1--;
    errors = min(e1, errors);
  }
  for (long long i = 0; i < k; i++)
    if (gs[i] != s[i]) e2++;
  errors = min(errors, e2);
  for (long long i = k; i < n; i++) {
    if (gs[i] != s[i]) e2++;
    if (gs[i - k] != s[i - k]) e2--;
    errors = min(e2, errors);
  }
  for (long long i = 0; i < k; i++)
    if (bs[i] != s[i]) e3++;
  errors = min(errors, e3);
  for (long long i = k; i < n; i++) {
    if (bs[i] != s[i]) e3++;
    if (bs[i - k] != s[i - k]) e3--;
    errors = min(e3, errors);
  }
  cout << errors << endl;
  return;
}
