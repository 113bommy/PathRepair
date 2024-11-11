#include <bits/stdc++.h>
using namespace std;
map<string, string> m;
int main() {
  long long int n, mm, i;
  string s, b, s1, b1;
  cin >> n >> mm;
  for (i = 0; i < n; i++) {
    cin >> s >> b;
    m[b] = s;
  }
  char c;
  for (i = 0; i < mm; i++) {
    cin >> s1 >> b1;
    int l = b1.length();
    cout << s1 << " " << b1.substr(0, l - 1) << " #" << m[b1.substr(0, l - 1)]
         << "\n";
  }
}
