#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int a, b, s;
  cin >> a >> b >> s;
  if (s > (abs(a) + abs(b)) || (s - (abs(a) + abs(b))) % 2 != 0)
    cout << "No";
  else
    cout << "Yes";
}
