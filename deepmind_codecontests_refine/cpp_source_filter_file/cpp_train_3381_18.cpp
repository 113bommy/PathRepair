#include <bits/stdc++.h>
using namespace std;
int a, b, s;
int main() {
  cin >> a >> b >> s;
  if (s >= abs(a) + abs(b) && (s - (abs(a) + abs(b)) % 2))
    cout << "Yes";
  else
    cout << "No";
}
