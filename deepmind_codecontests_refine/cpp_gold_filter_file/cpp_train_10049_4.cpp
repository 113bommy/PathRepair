#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long n, k;
  cin >> n >> k;
  unsigned long long answer = 0;
  while ((k > 0) && (n > 1)) {
    answer += (n - 2) * 2 + 1;
    k--;
    n -= 2;
  }
  cout << answer;
}
