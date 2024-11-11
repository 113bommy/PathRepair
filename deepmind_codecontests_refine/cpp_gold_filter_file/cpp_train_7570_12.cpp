#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  for (long long int i = 1; i <= s.size(); i++) {
    if (n % i == 0) {
      reverse(s.begin(), s.begin() + i);
    }
  }
  cout << s;
}
