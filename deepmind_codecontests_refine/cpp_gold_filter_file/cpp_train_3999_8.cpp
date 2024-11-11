#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int sum = 0;
  int s[100000];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    if (s[i] != s[i + 1]) sum += 1;
  }
  cout << sum << endl;
  return 0;
}
