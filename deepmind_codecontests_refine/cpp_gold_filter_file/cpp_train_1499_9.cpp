#include <bits/stdc++.h>
using namespace std;
int main() {
  map<string, int> a;
  map<string, int> b;
  int n;
  cin >> n;
  int* x = new int[n];
  string* s = new string[n];
  int maxScore = INT_MIN;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    cin >> x[i];
    a[s[i]] += x[i];
  }
  for (int i = 0; i < n; i++) {
    maxScore = max(maxScore, a[s[i]]);
  }
  for (int i = 0; i < n; i++) {
    b[s[i]] += x[i];
    if (b[s[i]] >= maxScore && a[s[i]] == maxScore) {
      cout << s[i];
      break;
    }
  }
}
