#include <bits/stdc++.h>
long long l, r;
int K;
int main() {
  scanf("%I64d%I64d%d", &l, &r, &K);
  if (K == 1) {
    printf("%I64d %d %I64d\n", l, 1, l);
    return 0;
  }
  std::map<long long, long long> map;
  std::vector<long long> out;
  out.push_back(l);
  long long answer = l;
  for (int i = 0; i <= std::min(r - l - 1, 1000000LL); ++i) {
    long long value = l + i ^ l + i + 1;
    if (value < answer) {
      answer = value;
      out.clear();
      out.push_back(l + i);
      out.push_back(l + i + 1);
    }
    if (K >= 4 && map.find(value) != map.end()) {
      int temp = map[value];
      if (temp + 1 < l + i) {
        answer = 0;
        out.clear();
        out.push_back(temp);
        out.push_back(temp + 1);
        out.push_back(l + i);
        out.push_back(l + i + 1);
        break;
      }
    }
    if (K >= 4 && map.find(value) == map.end()) {
      map[value] = l + i;
    }
  }
  if (K >= 3) {
    for (int i = 0; i < std::min(1000000LL, r - l); ++i) {
      long long a, b, c;
      a = l + i;
      for (b = 1; b <= a; b <<= 1)
        ;
      b ^= b >> 1;
      c = a ^ b;
      if (c <= r && b <= r) {
        answer = 0;
        out.clear();
        out.push_back(a);
        out.push_back(b);
        out.push_back(c);
        break;
      }
    }
  }
  printf("%I64d\n", answer);
  printf("%d\n", (int)out.size());
  for (int i = 0; i < (int)out.size(); ++i) {
    printf("%I64d ", out[i]);
  }
  puts("");
  return 0;
}
