#include <bits/stdc++.h>
using namespace std;
long long n, k;
bool valid(long long mid) {
  long long mx = k - 1;
  long long val = mx * (mx + 1) / 2 - (mx - mid) * (mx - mid + 1) / 2 + 1;
  return n <= val;
}
long long bs() {
  long long st = 1, ed = k - 1;
  while (st < ed) {
    long long mid = st + (ed - st) / 2;
    if (valid(mid)) {
      ed = mid;
    } else {
      st = mid + 1;
    }
  }
  long long mx = k - 1;
  long long val = mx * (mx + 1) / 2 - (mx - st) * (mx - st + 1) / 2 + 1;
  return n <= val ? st : -1;
}
int main() {
  cin >> n >> k;
  cout << bs();
}
