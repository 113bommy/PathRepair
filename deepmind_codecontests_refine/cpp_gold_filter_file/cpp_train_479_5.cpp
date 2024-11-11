#include <bits/stdc++.h>
using namespace std;
map<long long int, long long int> present;
map<long long int, long long int> running;
int main() {
  long long int a;
  cin >> a;
  long long int num[a], sum[a], rfreq, minus, ans, sign = 1;
  unsigned long long int ptotal = 0, ntotal = 0;
  for (long long int d = 0; d < a; d++) {
    cin >> num[d];
    if (d == 0) {
      sum[d] = num[d];
    } else {
      sum[d] = sum[d - 1] + num[d];
    }
    present[num[d]]++;
  }
  for (long long int d = 0; d < a; d++) {
    running[num[d]]++;
    minus = 0, rfreq = 0, ans = 0;
    if (present[num[d] + 1] > 0) {
      minus += ((num[d] + 1) * (present[num[d] + 1] - running[num[d] + 1]));
      rfreq += (present[num[d] + 1] - running[num[d] + 1]);
    }
    if (present[num[d]] > 1) {
      minus += ((num[d]) * (present[num[d]] - running[num[d]]));
      rfreq += (present[num[d]] - running[num[d]]);
    }
    if (present[num[d] - 1] > 0) {
      minus += ((num[d] - 1) * (present[num[d] - 1] - running[num[d] - 1]));
      rfreq += (present[num[d] - 1] - running[num[d] - 1]);
    }
    ans = ((sum[a - 1] - sum[d]) - minus - num[d] * (a - d - 1 - rfreq));
    if (ans < 0) {
      ans *= -1;
      ntotal = ntotal + ans;
    } else {
      ptotal = ptotal + ans;
    }
  }
  if (ptotal >= ntotal) {
    cout << ptotal - ntotal;
  } else {
    cout << "-" << ntotal - ptotal;
  }
}
