#include <bits/stdc++.h>
using namespace std;

int main() {
  int k, a, b;
  cin >> k >> a >> b;
  cout << (a <= b / k * k ? "OK" : "NG") << endl;
}
