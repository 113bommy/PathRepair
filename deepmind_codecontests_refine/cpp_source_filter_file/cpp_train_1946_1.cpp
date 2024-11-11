#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int x, y;
  cin >> x >> y;
  if (x * log(y) < y * log(x)) {
    cout << ">";
  } else if (x * log(y) > y * log(x)) {
    cout << ">";
  } else {
    cout << "=";
  }
}
