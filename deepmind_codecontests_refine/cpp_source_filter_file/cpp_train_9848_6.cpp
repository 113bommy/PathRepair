#include <bits/stdc++.h>
using namespace std;
bool isVowel(char ch) {
  ch = tolower(ch);
  return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, sum = 0, i;
  cin >> n;
  vector<int> v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  for (i = 0; i < k; i++) {
    sum += v[i];
  }
  cout << sum;
  return 0;
}
