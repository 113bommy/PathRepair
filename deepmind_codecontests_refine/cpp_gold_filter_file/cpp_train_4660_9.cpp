#include <bits/stdc++.h>
using namespace std;
vector<long long> fenv(1000000);
long long n;
void addfenv(int p, int x) {
  for (; p < n; p |= p + 1) fenv[p] += x;
}
long long getfenv(int r) {
  long long res = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) res += fenv[r];
  return res;
}
int main() {
  cin >> n;
  vector<long long> arr(n);
  for (auto &i : arr) cin >> i, --i;
  long long cnt = 0;
  for (int i = n - 1; i >= 0; --i) cnt += getfenv(arr[i]), addfenv(arr[i], 1);
  if (cnt % 2 == n % 2)
    cout << "Petr";
  else
    cout << "Um_nik";
  return 0;
}
