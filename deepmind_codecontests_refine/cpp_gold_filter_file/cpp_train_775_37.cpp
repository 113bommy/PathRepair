#include <bits/stdc++.h>
using namespace std;
void swap(long long &a, long long &b) {
  long long t;
  t = a;
  a = b;
  b = t;
}
int main() {
  ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  long long n1, n2, k1, k2;
  cin >> n1 >> n2 >> k1 >> k2;
  if (n1 > n2)
    cout << "First" << endl;
  else
    cout << "Second" << endl;
  return 0;
}
