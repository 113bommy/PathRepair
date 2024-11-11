#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a = 0, b = 1;
  vector<int> arr = {0};
  while (b <= n) {
    arr.push_back(b);
    b = a + b, a = arr.back();
  }
  n -= arr.back();
  int l = 0, r = arr.size() - 1;
  while (l <= r) {
    int s = arr[l] + arr[r];
    if (s == n) {
      cout << arr.back() << ' ' << arr[l] << ' ' << arr[r] << '\n';
      return;
    } else if (s < n)
      l++;
    else
      r--;
  }
  cout << "I'm too stupid to solve this problem"
       << "\n";
}
int main() { solve(); };
