#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int a, b, c, d, i, j, e;
  vector<long long int> v, ve;
  cin >> a;
  for (j = 0; j < a; j++) {
    cin >> b;
    string s;
    long long int k = b / 4;
    if (b % 4 != 0) k++;
    for (i = 0; i < b - k; i++) {
      s += '9';
    }
    for (i = 0; i < k; i++) {
      s += 8;
    }
    cout << s << "\n";
  }
}
