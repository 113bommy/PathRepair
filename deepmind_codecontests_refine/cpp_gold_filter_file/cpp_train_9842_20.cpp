#include <bits/stdc++.h>
using namespace std;
int main() {
  double d, h, v, e;
  double pi = 3.1415926535897;
  cin >> d >> h >> v >> e;
  if (v / ((pi * d * d) / 4) > e) {
    cout << "YES\n";
    cout << (h / (v / ((pi * d * d) / 4) - e));
  } else
    cout << "NO";
  cin >> d;
}
