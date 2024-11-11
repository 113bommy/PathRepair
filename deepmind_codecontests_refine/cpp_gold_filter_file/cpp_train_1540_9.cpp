#include <iostream>
using namespace std;

int main() {
  int n, m, sum = 0;
  cin >> n >> m;
  for (int a; cin >> a; sum += a) {}
  cout << (n - sum >= 0 ? n - sum : -1);
  return 0;
}
