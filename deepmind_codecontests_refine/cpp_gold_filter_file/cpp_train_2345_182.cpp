#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, div2, div3, div5, div7;
  cin >> n;
  div2 = n / 2;
  div3 = n / 3 - n / (2 * 3);
  div5 = n / 5 - n / (2 * 5) - n / (3 * 5) + n / (2 * 3 * 5);
  div7 = n / 7 - n / (2 * 7) - n / (3 * 7) + n / (2 * 3 * 7) - n / (5 * 7) +
         n / (2 * 5 * 7) + n / (3 * 5 * 7) - n / (2 * 3 * 5 * 7);
  cout << n - (div2 + div3 + div5 + div7) << endl;
}
