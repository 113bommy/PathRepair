#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, b, d;
  cin >> n >> b >> d;
  int64_t count = 0;
  int64_t in;
  int64_t answer = 0;
  for (int64_t i = 0; i < n; i++) {
    cin >> in;
    if (in <= b) {
      count += in;
    }
    if (count && count > d) {
      answer++;
      count = 0;
    }
  }
  if (count && count > d) {
    answer++;
  }
  { cout << answer; }
  return 0;
}
