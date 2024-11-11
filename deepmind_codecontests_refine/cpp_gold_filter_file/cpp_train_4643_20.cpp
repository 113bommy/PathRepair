#include <bits/stdc++.h>
using namespace std;
int power(int a, int b) {
  int res = 1;
  while (b) {
    if (b % 2) {
      res = (res * a) % 1000000007;
    }
    b /= 2;
    a = (a * a) % 1000000007;
  }
  return res;
}
const int C = 26;
string s, ans;
stack<int> t;
vector<int> pos[C];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  for (int i = 0; i < s.length(); i++) pos[s[i] - 'a'].push_back(i);
  int ptr = 0;
  for (__typeof(C - 1) c = 0; c <= C - 1; c++) {
    for (int i : pos[c]) {
      while (!t.empty() && t.top() <= c) {
        cout << (char)(t.top() + 'a');
        t.pop();
      }
      if (i >= ptr) {
        for (__typeof(i - 1) j = ptr; j <= i - 1; j++) t.push(s[j] - 'a');
        cout << ((char)(c + 'a'));
        ptr = i + 1;
      }
    }
  }
  while (!t.empty()) {
    cout << ((char)(t.top() + 'a'));
    t.pop();
  }
  return 0;
}
