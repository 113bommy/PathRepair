#include <bits/stdc++.h>
using namespace std;
string st;
int main() {
  cin >> st;
  char q[10] = {'A', 'I', 'O', 'M', 'H', 'U', 'V', 'W', 'X', 'Y'};
  set<char> s(q, q + 10);
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
