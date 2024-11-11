#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    long long s, a, b, c;
    cin >> s >> a >> b >> c;
    s = s / c + (s / a) * b;
    cout << s << endl;
  }
}
