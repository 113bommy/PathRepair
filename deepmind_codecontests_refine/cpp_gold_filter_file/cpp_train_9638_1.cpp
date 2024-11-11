#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  vector<char> out(n);
  int fill = 0;
  char cur_char = 'a';
  for (int i = n - 1; i >= 0; i--) {
    while (c[i] > 0) {
      for (int j = 0; j <= i; j++) {
        out[fill] = cur_char;
        fill++;
        c[i - j] -= (j + 1);
      }
      cur_char += 1;
      if (cur_char > 'z') cur_char = 'a';
    }
  }
  for (char c : out) {
    cout << c;
  }
  cout << '\n';
  return 0;
}
