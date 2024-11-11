#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream ff("file.txt");
  long long n, k, sum = 0, cur = 0;
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    long long a;
    scanf("%d", &a);
    if (i > 1 && (sum - (i - cur - 1) * (n - i) * a < k)) {
      cout << i << endl;
      cur++;
    } else {
      sum += a * (i - cur - 1);
    }
  }
  return 0;
}
