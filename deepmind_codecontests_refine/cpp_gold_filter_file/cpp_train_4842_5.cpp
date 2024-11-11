#include <bits/stdc++.h>
using namespace std;
string s[100 + 5];
int n;
int MAX;
bool ok(string a, int b, int c) {
  for (int i = 0; i < a.size(); i++)
    if (a[i] - 'a' != b && a[i] - 'a' != c) return false;
  return true;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i <= 'z' - 'a'; i++) {
    for (int j = 0; j <= i; j++) {
      int sum = 0;
      for (int k = 0; k < n; k++)
        if (ok(s[k], i, j)) sum += s[k].size();
      if (sum > MAX) MAX = sum;
    }
  }
  cout << MAX << endl;
}
