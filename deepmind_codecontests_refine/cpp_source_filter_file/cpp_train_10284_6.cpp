#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, a, b;
  cin >> k >> a >> b;
  cout << ((b / k * k >= a) ? "NG" : "OK") << endl;
}
