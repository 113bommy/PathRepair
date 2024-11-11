#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  string str;
  cin >> str;
  for (long long i = 0; i < b; i++) {
    char c1, c2;
    long long x, y;
    cin >> x >> y >> c1 >> c2;
    for (long long j = x; j <= y; j++) {
      if (str[j - 1] == c1) str[j - 1] = c2;
    }
  }
  cout << str << endl;
  return 0;
}
