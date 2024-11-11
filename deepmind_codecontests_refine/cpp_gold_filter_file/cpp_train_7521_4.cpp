#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int_fast64_t t, n, no[500], max;
  cin >> t;
  string a;
  while (t--) {
    cin >> n;
    max = 0;
    a = "";
    for (int_fast64_t i = 1; i <= n; ++i) {
      cin >> no[i];
      max = fmax(max, no[i]);
    }
    char c = 'a';
    for (int_fast64_t i = 0; i < max + 1; ++i) {
      a += 'a';
    }
    cout << a << "\n";
    char temp = 'a';
    for (int_fast64_t i = 1; i <= n; ++i) {
      temp++;
      for (int_fast64_t j = no[i]; j < a.length(); ++j) a[j] = temp;
      ;
      cout << a << endl;
      if (temp == 'z') temp = 'a';
    }
  }
  return 0;
}
