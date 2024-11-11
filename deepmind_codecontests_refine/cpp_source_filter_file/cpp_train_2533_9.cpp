#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int castor(int n) {
    if (n == 1) return 1;
    for (int i = 2; i * i <= n; i++) {
      if (n % 2 == 0) return n + castor(n / i);
    }
    return n + castor(n / n);
  }
};
int main() {
  Solution obj;
  int a;
  cin >> a;
  cout << obj.castor(a) << endl;
  return 0;
}
