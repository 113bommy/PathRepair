#include <bits/stdc++.h>
using namespace std;
int main() {
  int size;
  cin >> size;
  string s;
  cin >> s;
  for (int i = 1; i <= size; i++) {
    if (size % i) {
      reverse(s.begin(), s.begin() + i);
    }
  }
  cout << s << endl;
  return 0;
}
