#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  string st;
  cin >> st;
  int count(1);
  int ans(0);
  for (int i = 0; i < st.length(); i++) {
    if (st[i] == st.length() - 1) {
      break;
    }
    if (count == 5) {
      ans++;
      count = 0;
    }
    if (st[i] == st[i + 1]) {
      count++;
    }
    if (count < 5 && st[i] != st[i + 1]) {
      ans++;
      count = 0;
    }
  }
  cout << ans << endl;
  return EXIT_SUCCESS;
}
