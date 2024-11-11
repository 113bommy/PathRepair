#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int k = 0;
  string sp = "aeuio13579";
  for (int i = 0; i < s.size(); i++) {
    if (sp.find(s[i]) != -1) {
      k++;
    }
  }
  cout << k;
}
