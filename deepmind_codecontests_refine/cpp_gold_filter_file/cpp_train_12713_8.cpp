#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  cout << (int)(ceil((double)2 * n / k) + ceil((double)5 * n / k) +
                ceil((double)8 * n / k))
       << endl;
  return 0;
}
