#include <bits/stdc++.h>
using namespace std;
string s[150];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long N, i, x, j, k = 0;
  string a, b, c;
  cin >> N;
  for (i = 0; i < N; i++) {
    long long FF = 0;
    cin >> b >> c;
    a = b + " " + c;
    for (j = 0; j < k; j++) {
      if (a == s[j]) FF = 1;
    }
    if (FF == 0) {
      s[k] = a;
      k++;
    }
  }
  cout << k;
  return 0;
}
