#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  if (s < t) {
    puts("Yes");
  } else {
    puts("No");
  }
  return 0;
}
