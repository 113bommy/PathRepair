#include <bits/stdc++.h>
using namespace std;
const int maxElments = 2e5;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  string a, b;
  cin >> a >> b;
  int count = 0, last = b.size();
  for (int i = 0; i < a.size(); i++) {
    if (a.substr(i, last) == b) {
      count++;
      i += last - 1;
    }
  }
  cout << count << '\n';
  return 0;
}
