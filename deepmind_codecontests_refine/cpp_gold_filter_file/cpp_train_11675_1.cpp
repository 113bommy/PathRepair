#include <bits/stdc++.h>
using namespace std;
string h = "0", t = "1", rem = "2 3 4 5 6 7 8 9";
long long query(long long no) {
  if (no == 2)
    cout << "next"
         << " " << h << " " << t << "\n";
  else if (no == 1)
    cout << "next"
         << " " << h << "\n";
  else
    cout << "next"
         << " " << h << " " << t << " " << rem << "\n";
  cout.flush();
  long long n;
  cin >> n;
  string s;
  for (long long int i = 0; i < n; i++) cin >> s;
  return n;
}
int solve() {
  long long ans;
  long long n = 0;
  ans = query(2);
  ans = query(1);
  while (ans == 3) {
    ans = query(2);
    ans = query(1);
  }
  while (ans == 2) {
    ans = query(3);
  }
  if (ans == 1) {
    cout << "done";
    cout.flush();
  } else
    cout << "fucked up";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
}
