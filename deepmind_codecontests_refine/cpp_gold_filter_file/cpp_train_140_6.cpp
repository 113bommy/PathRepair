#include <bits/stdc++.h>
using namespace std;
string st;
int num;
int main() {
  cin >> st;
  cin >> num;
  for (int i = 0; i < st.size(); i++) {
    int p = int(st[i]);
    if (p < 97) p += 32;
    if (p < num + 97) p -= 32;
    cout << char(p);
  }
  cout << endl;
  return 0;
}
