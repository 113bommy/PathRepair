#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, answer = 0;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] != s[i + 1]) {
      answer++;
      i++;
    }
  }
  cout << answer << endl;
  return 0;
}
