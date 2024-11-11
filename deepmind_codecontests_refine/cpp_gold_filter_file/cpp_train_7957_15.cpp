#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = 26;
  int w[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  int max = *max_element(w + 1, w + n + 1);
  int l = s.length();
  int score = 0;
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < 26; j++) {
      if (s[i] == char(j + 'a')) {
        score = score + (i + 1) * w[j + 1];
      }
    }
  }
  for (int o = l + 1; o <= l + k; o++) {
    score = score + o * max;
  }
  cout << score;
  return 0;
}
