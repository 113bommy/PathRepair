#include <iostream>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  cout << k == 1 ? 0 : n - k << '\n';
}