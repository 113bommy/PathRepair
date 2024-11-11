#include <bits/stdc++.h>
using namespace std;
int main() {
  map<char, int> f, l;
  string a, b;
  getline(cin, a);
  getline(cin, b);
  for (int i = 0; i < a.size(); i++) f[a[i]]++;
  for (int i = 0; i < b.size(); i++) l[b[i]]++;
  for (int i = 0; i < b.size(); i++) {
    if (b[i] == ' ') continue;
    if (f[b[i]] < l[b[i]]) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}
