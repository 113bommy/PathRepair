#include <bits/stdc++.h>
using namespace std;
string st;
int main() {
  cin >> st;
  char q[11] = {'A', 'I', 'O', 'M', 'H', 'U', 'V', 'W', 'X', 'Y', 'T'};
  set<char> s(q, q + 11);
  for (long long i = 0; i < st.size() / 2 + 1; i++) {
    if (st[i] != st[st.size() - i - 1] || s.count(st[i]) == 0) {
      cout << "NO";
      return 0;
    }
  }
  if (st.size() == 1) {
    if (s.count(st[0]) == 0) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}
