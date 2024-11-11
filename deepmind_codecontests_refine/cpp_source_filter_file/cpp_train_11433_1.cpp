#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  if (s.size() == 3) {
    reverse(begin(s), end(s));
  }
  cout << s << endl;
}
