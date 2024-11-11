#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e9;
int A1 = 2, B1 = 3, A2 = 4, B2 = 5;
int ask(int i, int j) {
  cout << "? " << i << " " << j << endl;
  int ans;
  cin >> ans;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int A = ask(1, 1);
  int B = ask(1, N);
  int l = 1, r = N;
  while (l < r) {
    int mid = (l + r) / 2;
    if (ask(1, mid) == B - (N - mid))
      r = mid;
    else
      l = mid + 1;
  }
  int a1, b1;
  int a2, b2;
  b2 = l;
  a1 = 1 + ask(1, l);
  a2 = N - ask(N, l);
  b1 = A - (a1 - 1) + 1;
  cout << "! " << a1 << " " << b1 << " " << a2 << " " << b2 << endl;
  return 0;
}
