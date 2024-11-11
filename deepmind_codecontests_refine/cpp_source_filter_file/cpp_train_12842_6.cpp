#include <bits/stdc++.h>
using namespace std;
int A, B, K;
bool composed[1000100];
void ciur() {
  composed[1] = false;
  for (int i = 2; i < 1000100; i++)
    if (composed[i] == false)
      for (int j = i + i; j < 1000100; j += i) composed[j] = true;
}
bool check(int L) {
  int cnt = 0, i;
  for (i = B; i >= A; i--) {
    cnt += (composed[i] == false);
    if (i + L <= B) cnt -= (composed[i + L] == false);
    if (i <= B - L + 1 && cnt < K) return false;
  }
  return true;
}
int main() {
  cin >> A >> B >> K;
  int st = 1, dr = B - A + 1, mid, res = -1;
  ciur();
  while (st <= dr) {
    mid = (st + dr) / 2;
    if (check(mid))
      res = mid, dr = mid - 1;
    else
      st = mid + 1;
  }
  cout << res;
  return 0;
}
