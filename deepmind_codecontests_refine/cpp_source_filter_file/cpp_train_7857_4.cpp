#include <bits/stdc++.h>
using namespace std;
int i;
int main() {
  int n;
  cin >> n;
  string s[n];
  for (i = 0; i < n; i++) {
    cin >> s[i];
  }
  int c = 1, best = 0;
  for (i = 0; i < n - 1; i++) {
    c = 1;
    for (int j = i + 1; j < n; j++) {
      if (s[i].compare(s[j]) == 0) {
        c++;
      }
    }
    best = max(best, c);
  }
  cout << best;
}
