#include <bits/stdc++.h>
using namespace std;
map<string, int> x;
int main() {
  string w;
  cin >> w;
  for (int i = 0; i < (int)10; ++i) {
    string a;
    cin >> a;
    x[a] = i;
  }
  int j = 0;
  for (int i = 0; i < (int)10; ++i) {
    string q = "";
    for (int t = 0; t < (int)10; ++t) q += w[j++];
    cout << x[q];
  }
  return 0;
}
