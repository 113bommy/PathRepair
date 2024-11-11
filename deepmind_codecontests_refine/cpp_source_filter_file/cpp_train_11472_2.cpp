#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int32_t n;
  int64_t k;
  std::cin >> n >> k;
  std::pair<int64_t, int64_t>* segments = new std::pair<int64_t, int64_t>[n];
  int64_t min_length = INT64_MAX;
  for (int32_t i = 0; i < n; i++) {
    std::cin >> segments[i].first >> segments[i].second;
    min_length = std::min(min_length, segments[i].second - segments[i].first);
  }
  std::vector<int64_t> lucky;
  for (int32_t i = 1; i <= 17; i++) {
    for (int32_t j = 0; j < (1 << i); j++) {
      int64_t cur = 0;
      for (int32_t p = 0; p < i; p++) {
        cur *= 10;
        cur += (j & (1ll << p)) > 0 ? 4 : 7;
      }
      lucky.push_back(cur);
    }
  }
  std::sort(lucky.begin(), lucky.end());
  std::vector<int64_t> begins, ends;
  for (int32_t i = 0; i < n; i++) {
    begins.push_back(segments[i].first);
    ends.push_back(segments[i].second);
  }
  std::sort(begins.begin(), begins.end());
  std::sort(ends.begin(), ends.end());
  __int128_t* end_pref_sum = new __int128_t[n + 1];
  end_pref_sum[0] = 0;
  for (int32_t i = 1; i <= n; i++)
    end_pref_sum[i] = end_pref_sum[i - 1] + ends[i - 1];
  __int128_t* begin_suf_sum = new __int128_t[n + 1];
  begin_suf_sum[0] = 0;
  for (int32_t i = 1; i <= n; i++)
    begin_suf_sum[i] = begin_suf_sum[i - 1] + begins[n - i];
  int32_t answer = 0;
  for (int32_t i = 0; i < lucky.size(); i++) {
    int32_t num_end_less =
        std::lower_bound(ends.begin(), ends.end(), lucky[i]) - ends.begin();
    int32_t num_start_more =
        n - (std::lower_bound(begins.begin(), begins.end(), lucky[i]) -
             begins.begin());
    __int128_t remains =
        k - ((__int128_t)num_end_less * lucky[i] - end_pref_sum[num_end_less]);
    remains -=
        begin_suf_sum[num_start_more] - (__int128_t)num_start_more * lucky[i];
    if (remains < 0) continue;
    int32_t maximum_added = std::lower_bound(lucky.begin(), lucky.end(),
                                             lucky[i] + min_length + 1) -
                            lucky.begin();
    int32_t left = 1, right = maximum_added - i + 1;
    while (right - left > 1) {
      int32_t m = (left + right) / 2;
      __int128_t needed =
          num_end_less * (__int128_t)(lucky[i + m - 1] - lucky[m]);
      int32_t num_ends_less2 =
          std::lower_bound(ends.begin(), ends.end(), lucky[i + m - 1]) -
          ends.begin();
      needed +=
          ((__int128_t)(num_ends_less2 - num_end_less) * lucky[i + m - 1]) -
          (end_pref_sum[num_ends_less2] - end_pref_sum[num_end_less]);
      if (needed <= remains)
        left = m;
      else
        right = m;
    }
    answer = std::max(answer, left);
  }
  std::cout << answer;
  return 0;
}
