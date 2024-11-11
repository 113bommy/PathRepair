#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  long long count = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B') count += pow(2, i);
  }
  cout << count << endl;
  return 0;
}
