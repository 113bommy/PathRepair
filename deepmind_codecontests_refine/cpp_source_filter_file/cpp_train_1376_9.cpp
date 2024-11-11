#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
const int N = (int)1e5 + 10;
void TimeExecution() {
  cout << "\n\n===>> Time Execution: " << clock() / (double)1000 << " sec(s).";
}
int t;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string t1, t2, t3;
    t1 = s.substr(s.size() - 2, 2);
    if (s.size() > 4) t2 = s.substr(s.size() - 4, 4);
    if (s.size() > 5) t3 = s.substr(s.size() - 5, 5);
    if (t1 == "po")
      cout << "FILIPINO";
    else if (t2 == "desu" || t2 == "masu")
      cout << "JAPANESE";
    else if (t3 == "mnida")
      cout << "KOREAN";
    cout << '\n';
  }
  return 0;
}
