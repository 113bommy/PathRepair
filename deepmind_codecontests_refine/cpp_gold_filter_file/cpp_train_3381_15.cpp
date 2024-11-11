#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, s;
  cin >> a >> b >> s;
  if (s >= abs(a) + abs(b) && (s - (abs(a) + abs(b))) % 2 == 0) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}
