#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long a, b, s;
  cin >> a >> b >> s;
  if (abs(a) + abs(b) > abs(s)) {
    cout << "No" << endl;
  } else {
    cout << (((s - a - b + 2000000008) % 2 == 0) ? "Yes" : "No") << "\n";
  }
}
