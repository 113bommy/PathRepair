#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long a, b;
    long long uns = 0;
    cin >> a >> b;
    uns = abs(a - b) / 5;
    if (abs(a - b) % 5 == 1) uns++;
    if (abs(a - b) % 5 == 2) uns += 1;
    if (abs(a - b) % 5 == 3) uns += 2;
    if (abs(a - b) % 5 == 4) uns += 2;
    cout << uns << endl;
  }
}
