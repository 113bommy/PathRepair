#include <bits/stdc++.h>
using namespace std;
vector<long long> part_len = {0,
                              45,
                              9045,
                              1395495,
                              189414495,
                              23939649495,
                              2893942449495,
                              339393974949495,
                              38939394344949495,
                              4393939398494949495};
vector<long long> prefix_len = {0,        0,         9,         189,
                                2889,     38889,     488889,    5888889,
                                68888889, 788888889, 8888888889};
vector<long long> start_num = {0,        1,         10,        100,
                               1000,     10000,     100000,    1000000,
                               10000000, 100000000, 1000000000};
int getPartNum(long long k) {
  int high = part_len.size() - 1;
  int low = 0;
  int mid;
  while (high > low) {
    mid = (high + low) / 2;
    if (part_len[mid] > k) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return part_len[mid] < k ? mid + 1 : mid;
}
int getDigit(int n, long long k) {
  long long high = (prefix_len[n + 1] - prefix_len[n]) / n;
  long long low = 1;
  long long mid;
  while (high > low) {
    mid = (high + low) >> 1;
    long long num_len = mid - low + 1;
    long long tmp = num_len * (mid + low) / 2 * n + num_len * prefix_len[n];
    if (tmp < k) {
      k -= tmp;
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  for (n = 1; k > prefix_len[n]; ++n)
    ;
  --n;
  long long num = (k - prefix_len[n] - 1) / n + start_num[n];
  long long digit_index = n - (k - prefix_len[n] - 1) % n;
  return (num / start_num[digit_index]) % 10;
}
int main() {
  int q;
  long long k;
  cin >> q;
  while (q--) {
    cin >> k;
    int part_num = getPartNum(k);
    long long part_k = k - part_len[part_num - 1];
    int target_digit = getDigit(part_num, part_k);
    cout << target_digit << endl;
  }
  return 0;
}
