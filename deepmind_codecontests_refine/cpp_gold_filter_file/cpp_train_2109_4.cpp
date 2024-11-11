#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  scanf("%lld", &t);
  while (t--) {
    long long int n, i;
    scanf("%lld", &n);
    string s, w1 = "", w = "";
    cin >> s;
    long long int x = 0, k = 0, j = 0;
    i = 0;
    while (x == 0) {
      if (s[i] == '0') {
        w = w + s[i];
        j++;
      } else
        break;
      i++;
    }
    j--;
    i = n - 1;
    while (x == 0) {
      if (s[i] == '1')
        k++;
      else
        break;
      i--;
    }
    if (i <= j) i++;
    ;
    for (i = i; i < n; i++) w1 = w1 + s[i];
    w1 = w + w1;
    cout << w1 << endl;
  }
}
