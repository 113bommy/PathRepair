#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, k;
  cin >> n >> k;
  vector<int> a;
  {
    for (int i = 0; i < int(n); i++) {
      int x;
      cin >> x;
      a.push_back(x);
    }
  };
  int ai = 0;
  int an = n;
  long long sum = 0;
  for (int i = 0; i < int(n); i++) {
    if (sum - a[i] * (an - ai - 1) * (ai) < k) {
      cout << i + 1 << endl;
      an--;
      ai--;
    } else {
      sum += a[i] * (ai);
    }
    ai++;
  }
end:
  return 0;
}
