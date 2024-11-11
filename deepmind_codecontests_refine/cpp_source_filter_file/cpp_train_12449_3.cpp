#include <bits/stdc++.h>
using namespace std;
const int ndigit = 16;
long long read_hex() {
  char str[ndigit + 1];
  scanf("%s", str);
  long long result = 0;
  for (int i = 0; str[i] != '\0'; ++i) {
    int value;
    if (isdigit(str[i]))
      value = str[i] - '0';
    else
      value = str[i] - 'a' + 10;
    result = 16 * result + value;
  }
  return result;
}
vector<int> to_hex(long long value) {
  vector<int> result(ndigit);
  for (int i = ndigit - 1; i >= 0; --i) {
    result[i] = value % 16;
    value /= 16;
  }
  return result;
}
long long solve(long long limit, int max_digit_value, int bit_on_id) {
  long long result = 0;
  if (max_digit_value < 0) return result;
  int bit_digit = ndigit - 1 - bit_on_id / 4;
  int bit_mask = 1 << (bit_on_id % 4);
  vector<int> limit_hex = to_hex(limit);
  for (int eq_until = 0; eq_until + 1 < ndigit; ++eq_until) {
    long long nway = 1;
    for (int i = 0; i <= eq_until; ++i) {
      if (limit_hex[i] > max_digit_value) nway = 0;
      if (bit_digit == i && !(limit_hex[i] & bit_mask)) nway = 0;
    }
    int mid_nway = 0;
    for (int value = 0; value < limit_hex[eq_until + 1]; ++value) {
      bool ok = true;
      if (value > max_digit_value) ok = false;
      if (bit_digit == eq_until + 1 && !(value & bit_mask)) ok = false;
      if (ok) ++mid_nway;
    }
    nway *= mid_nway;
    for (int i = eq_until + 2; i < ndigit; ++i) {
      int digit_nway = 0;
      if (bit_digit == i) {
        for (int value2 = 0; value2 <= max_digit_value; ++value2)
          if (value2 & bit_mask) ++digit_nway;
      } else {
        digit_nway = max_digit_value + 1;
      }
      nway *= digit_nway;
    }
    result += nway;
  }
  return result;
}
long long solve(long long limit) {
  long long result = 0;
  if (limit == 0) return result;
  for (int highest = 0; highest < 16; ++highest) {
    result +=
        (solve(limit, highest, highest) - solve(limit, highest - 1, highest));
  }
  return result;
}
int main() {
  int nq;
  scanf("%d", &nq);
  for (int q = 0; q < nq; ++q) {
    long long left = read_hex(), right = read_hex();
    long long result = solve(right + 1) - solve(left);
    printf("%lld\n", result);
  }
  return 0;
}
