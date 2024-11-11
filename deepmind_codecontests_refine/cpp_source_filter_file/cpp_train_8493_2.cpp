#include <bits/stdc++.h>
using namespace std;
bool query(int x, int y) {
  cout << 1 << " " << x << " " << y << '\n';
  fflush(stdout);
  string s;
  cin >> s;
  return (s == "TAK");
}
void print(int a, int b) {
  cout << 2 << " " << min(a, b) << " " << max(a, b) << '\n';
  fflush(stdout);
}
int find1(int lo, int up) {
  if (lo >= up) return lo;
  int mid = (up + lo + 1) / 2;
  if (query(mid, mid + 1))
    up = mid;
  else
    lo = mid + 1;
  return find1(lo, up);
}
int find2(int lo, int up) {
  if (lo >= up) return lo;
  int mid = (up + lo) / 2;
  if (query(mid, mid + 1))
    up = mid;
  else
    lo = mid + 1;
  return find2(lo, up);
}
int main() {
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int sol1 = find1(1, n);
  int cand1 = find1(sol1 + 1, n);
  int cand2 = find2(1, sol1 - 1);
  if (sol1 == 1)
    print(sol1, cand1);
  else if (sol1 == n)
    print(sol1, cand2);
  else {
    if (query(cand1, cand2))
      print(sol1, cand1);
    else
      print(sol1, cand2);
  }
}
