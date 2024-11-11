#include <bits/stdc++.h>
using namespace std;
int main() {
  string st, s;
  cin >> st;
  long long f = 0, sz = st.size();
  for (long long i = 0; i < sz; i++) {
    if (st[i] == '0' && f == 0)
      f = 1;
    else
      s += st[i];
  }
  if (f)
    cout << s << endl;
  else {
    for (long long i = 0; i < sz; i++) cout << st[i];
  }
}
