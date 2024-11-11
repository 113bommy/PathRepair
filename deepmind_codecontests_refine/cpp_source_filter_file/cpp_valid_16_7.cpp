#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    char s[n], s1[n];
    cin >> s;
    strcpy(s1, s);
    int counter = 0;
    sort(s1, s1 + n);
    for (int i = 0; i < n; i++) {
      if (s1[i] != s[i]) counter++;
    }
    cout << counter << endl;
  }
  return 0;
}
