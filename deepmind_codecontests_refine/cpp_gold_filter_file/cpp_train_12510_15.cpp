#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
vector<long long> a;
long long k, n;
int main() {
  fast();
  long long flag = 0, x, y, t, ans = -1, apos;
  cin >> n >> k;
  int cur = 0, sum = 0, kush = 0;
  for (int i = 1; i <= n; i++) {
    sum += i;
    cur = i;
  }
  cur++;
  while (sum != k) {
    kush++;
    sum -= cur;
    cur--;
  }
  cout << kush;
}
