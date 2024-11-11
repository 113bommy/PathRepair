#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  cout << (n - n % 1000) % 1000 << "\n";
}
