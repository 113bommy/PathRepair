#include <bits/stdc++.h>
using namespace std;
using namespace std;
int n, m;
int main() {
  std::ios_base::sync_with_stdio(false);
  string s = "aeiou02468";
  string str;
  cin >> str;
  int x = 0;
  for (int i = 0; i < ((int)((str).size())); i++) {
    if (s.find(str[i]) != string::npos) ++x;
  }
  cout << x << "\n";
}
