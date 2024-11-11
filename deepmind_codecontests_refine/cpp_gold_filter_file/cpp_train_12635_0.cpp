#include <bits/stdc++.h>
using namespace std;
int n, k, x;
int num[100005];
bool cmp(int a, int b) { return abs(a) < abs(b); }
void make() {
  for (int i = n - 1; i >= 0; i--) {
    if (k == 0) return;
    if (num[i] < 0) {
      num[i] = num[i] * -1;
      k--;
    }
  }
  if (k % 2 == 0)
    return;
  else {
    num[0] = num[0] * -1;
    return;
  }
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }
  sort(num, num + n, cmp);
  make();
  long long sum = 0;
  for (int i = 0; i < n; i++) sum += num[i];
  cout << sum << endl;
  return 0;
}
