#include <bits/stdc++.h>
using namespace std;
int main() {
  char ch[3], ma[3];
  int store = 0;
  cin >> ch;
  for (int i = 0; i < 5; i++) {
    cin >> ma;
    if (ch[0] == ma[0] || ch[0] == ma[1] || ch[1] == ma[0] || ch[1] == ma[0]) {
      store = 1;
    }
  }
  if (store == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
