#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, s;
  cin >> a >> s;
  sort(s.begin(), s.end());
  int count = 0;
  int pos = s.size() - 1;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] < s[pos]) {
      a[i] = s[pos];
      pos++;
    }
  }
  cout << a << endl;
}
