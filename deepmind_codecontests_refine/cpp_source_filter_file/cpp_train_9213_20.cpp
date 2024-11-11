#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long int llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int op;
int mex(set<int>& s) {
  for (int i = 0; i < s.size() + 2; i++) {
    if (s.find(i) == s.end()) return i;
  }
}
int gru(int a) {
  if (op == 0) {
    if (a <= 2)
      return a;
    else {
      if (a % 2 == 1) return 0;
      return 1;
    }
  }
  if (op == 1) {
    set<int> s;
    if (a <= 3) {
      return (a % 2);
    }
    if (a % 2) return 1;
    s.insert(gru(a - 1));
    s.insert(gru(a / 2));
    return (mex(s));
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  op = k % 2;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    ans = ans ^ gru(a);
  }
  string s;
  if (ans == 0)
    s = "Nicky";
  else
    s = "Kevin";
  cout << s << endl;
}
