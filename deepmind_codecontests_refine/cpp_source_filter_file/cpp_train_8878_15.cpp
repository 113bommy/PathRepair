#include <bits/stdc++.h>
using namespace std;
int bf(int x) {
  vector<int> a;
  while (x != 0) {
    if (x % 10 == 4 || x % 10 == 7) a.push_back(x % 10);
    x /= 10;
  }
  long long int temp = 1, ans = 0;
  for (long long int i = 0; i < a.size(); i++) {
    ans += a[i] * temp;
    temp *= 10;
  }
  return ans;
}
int main() {
  int a, b;
  cin >> a >> b;
  int i = a;
  while (1) {
    long long int y = bf(i);
    if (y == b) {
      cout << i << endl;
      break;
    }
    i++;
  }
}
