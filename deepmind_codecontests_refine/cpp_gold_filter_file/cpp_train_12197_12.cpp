#include <bits/stdc++.h>
using namespace std;
map<char, int> mp;
char t[27];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, ans = 0, test = 0, test1 = 0, j = 0, i;
  string ch, ch1 = "aeiou";
  cin >> n;
  if (n < 25) {
    cout << -1;
    return 0;
  }
  for (int i = 5; i <= sqrt(n); i++) {
    if (n % i == 0) {
      test = i;
      break;
    }
  }
  if (test == 0) {
    cout << -1;
    return 0;
  }
  test1 = n / test;
  while (test1) {
    i = j;
    int cnt = 0;
    while (cnt < 5) {
      cout << ch1[i];
      i = (i + 1) % 5;
      cnt++;
    }
    for (int k = 0; k < test - 5; k++) cout << ch1[j];
    j = (j + 1) % 5;
    test1--;
  }
  return 0;
}
