#include <bits/stdc++.h>
using namespace std;
string st;
long ans[2000];
long answ;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> st;
  for (int i = 0; i < st.size(); i++) {
    ans[i] = 1;
    for (int j = 0; j < i; j++)
      if (st[j] == st[i] && j % 2 == i % 2) ans[i] = max(ans[i], ans[j] + 1);
  }
  answ = 0;
  for (int i = 0; i < st.size(); i++) answ = max(answ, ans[i]);
  cout << answ << endl;
  cin.get();
  cin.get();
  return 0;
}
