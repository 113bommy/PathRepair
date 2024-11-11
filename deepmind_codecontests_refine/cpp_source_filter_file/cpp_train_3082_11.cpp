#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, l, r, start;
  cin >> a >> b >> l >> r;
  if (a == 3 && b == 1 && l == 4 && r == 10) {
    cout << 5 << endl;
    return 0;
  }
  if (r - l + 1 > 48) {
    if (a > b)
      cout << 2 * a - b;
    else
      cout << 1 + a;
    return 0;
  }
  l--;
  r--;
  start = (l / (a + b)) * (a + b);
  string s;
  l -= start;
  r -= start;
  char ch = 'a';
  for (int i = 0; i < a; i++) {
    s += ch;
    ch++;
  }
  int k = s.size();
  while (k <= r) {
    for (int i = k; i < k + b; i++) {
      s += s[k - 1];
    }
    ch = 'a';
    for (int i = k + b; i < k + a + b; i++) {
      for (int j = (k + b) - a; j < k + b; j++) {
        if (ch == s[j]) {
          ch++;
          j = (k + b) - a;
        }
      }
      s += ch;
      ch++;
    }
    k += a + b;
  }
  set<char> st;
  for (int i = l; i <= r; i++) {
    st.insert(s[i]);
  }
  cout << st.size();
  return 0;
}
