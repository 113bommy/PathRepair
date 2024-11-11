#include <bits/stdc++.h>
int main() {
  uint64_t seq_len = 0;
  uint64_t guests_cnt = 0;
  scanf("%llu %llu", &seq_len, &guests_cnt);
  uint64_t cnt_arr[100] = {};
  memset(cnt_arr, 0x00, sizeof(uint64_t) * 100);
  uint64_t max_cnt = 0;
  for (uint64_t i = 0; i < seq_len; ++i) {
    uint64_t cur_type = 0;
    scanf("%llu", &cur_type);
    --cur_type;
    ++cnt_arr[cur_type];
    max_cnt = std::max(max_cnt, cnt_arr[cur_type]);
  }
  max_cnt = (max_cnt + guests_cnt + 1) - (max_cnt + 1) % guests_cnt;
  uint64_t ans = 0;
  for (uint64_t i = 0; i < 100; ++i) {
    if (cnt_arr[i]) {
      ans += (max_cnt - cnt_arr[i]);
    }
  }
  printf("%llu", ans);
  return 0;
}
