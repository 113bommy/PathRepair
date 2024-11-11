#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long t = 1, n, m;
string arr[] = {"January",   "February", "March",    "April",
                "May",       "June",     "July",     "August",
                "September", "October",  "November", "December"};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  long long idx = -1;
  for (int i = 0; i < 12; i++) {
    if (arr[i] == s) {
      idx = i;
      break;
    }
  }
  cin >> n;
  n %= 12;
  idx += n;
  idx %= 12;
  cout << arr[idx] << '\n';
}
