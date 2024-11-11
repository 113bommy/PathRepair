#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  cout << (x / 500) * 1000 + ((x % 1000) / 5) * 5 << endl;
}
