#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int a = 0, count = 0;
  for (int i = 0; i < s.size() - 1; i++) {
    count++;
    if (s[i] != s[i + 1]) {
      if (count % 2 == 0) a++;
      count = 0;
    }
  }
  cout << a << endl;
}
