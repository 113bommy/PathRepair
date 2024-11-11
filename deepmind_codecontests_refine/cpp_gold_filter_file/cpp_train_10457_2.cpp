#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, a, b;
  cin >> k >> a >> b;
  string str;
  cin >> str;
  int n = str.length();
  int ka = k * a;
  if (n < ka) {
    cout << "No solution";
    return 0;
  }
  int e = (n - ka) / k;
  int r = (n - ka) % k;
  if (a + e + (r > 0) > b) {
    cout << "No solution";
    return 0;
  }
  int j = 0;
  for (int i = 0; i < k; ++i) {
    int l = a + e + (i < r);
    while (l--) cout << str[j++];
    cout << endl;
  }
  return 0;
}
