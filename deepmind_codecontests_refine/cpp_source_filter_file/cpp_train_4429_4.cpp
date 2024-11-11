#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, c, i;
  cin >> n >> c;
  vector<int> s;
  s.resize(n);
  vector<int> t;
  t.resize(n);
  for (i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (i = 0; i < n; i++) {
    cin >> t[i];
  }
  int lmarks = 0, rmarks = 0, ltime = 0, rtime = 0;
  for (i = 0; i < n; i++) {
    ltime += t[i];
    lmarks += max(0, (s[i] - c * ltime));
    rtime += t[n - i - 1];
    rmarks += max(0, (s[n - i - 1] - c * rtime));
  }
  if (lmarks > rmarks) {
    cout << "Limak" << endl;
  } else if (lmarks = rmarks) {
    cout << "Tie" << endl;
  } else {
    cout << "Radewoosh" << endl;
  }
  return 0;
}
