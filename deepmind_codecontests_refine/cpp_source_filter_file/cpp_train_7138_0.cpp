#include <bits/stdc++.h>
using namespace std;
int n, a, i, k;
bool bar = 1;
string s;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a >> s;
    if (k == 0 && s != "South") bar = 0;
    if (k == 20000 && s != "North") bar = 0;
    if (s == "South") k += a;
    if (s == "North") k -= a;
    if (k < 0 || k > 20000) bar = 1;
  }
  if (!bar || k != 0)
    cout << "NO";
  else
    cout << "YES";
}
