#include <bits/stdc++.h>
using namespace std;
bool solve(int i) {
  set<int> st;
  int ct = 0;
  while (i) {
    st.insert(i % 10);
    i = i / 10;
    ct++;
  }
  if (st.size() == ct)
    return true;
  else {
    return false;
  }
}
int main(int argc, char** argv) {
  int l, r;
  cin >> l >> r;
  int el = -1;
  for (int i = l; i <= r; i++) {
    if (solve(i)) {
      el = i;
      break;
    }
  }
  cout << el << endl;
}
