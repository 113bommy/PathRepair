#include <bits/stdc++.h>
using namespace std;
long long vis[30];
int main() {
  string st;
  cin >> st;
  long long len = st.length();
  long long cn = 0;
  for (long long i = 0; i < len; i++) {
    long long k = st[i] - 'a';
    if (vis[k] == 0) {
      vis[k] = 1;
      cn++;
    }
  }
  long long ans = (len + 1) * 26 - len;
  cout << ans << endl;
  return 0;
}
