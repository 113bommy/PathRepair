#include <bits/stdc++.h>
using namespace std;
long long N, H;
long long find_ans(long long big, long long small) {
  if (big == small) return small;
  long long mid = (big + small) / 2;
  if (mid <= H + 1) {
    if ((mid <= 2000000000 && mid * (mid + 1) / 2 >= N) || mid > 2000000000)
      return find_ans(mid, small);
    else
      return find_ans(big, mid + 1);
  } else {
    if (mid > 2000000000) return find_ans(mid, small);
    long long x = (mid - H + 1) / 2, cnt;
    if ((mid - H) % 2 == 0) {
      cnt = (H + x) * (H + x + 1) / 2;
      cnt += (H + H + x - 1) * x / 2;
    } else {
      cnt = (H + x) * (H + x - 1) / 2;
      cnt += (H + H + x - 1) * x / 2;
    }
    if (cnt < N)
      return find_ans(big, mid + 1);
    else
      return find_ans(mid, small);
  }
}
int main() {
  cin >> N >> H;
  cout << find_ans(N + 1, 1) << endl;
  return 0;
}
