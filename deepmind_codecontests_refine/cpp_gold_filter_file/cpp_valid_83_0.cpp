#include <bits/stdc++.h>
int32_t n;
std::string str;
int32_t *suf_array, *inverse_suf_array;
void radix_sort(int32_t* classes) {
  int32_t m = str.size();
  int32_t* counters = new int32_t[m];
  for (int32_t i = 0; i < m; i++) counters[i] = 0;
  for (int32_t i = 0; i < m; i++) counters[classes[i]]++;
  int32_t last = 0;
  for (int32_t i = 0; i < m; i++) {
    int32_t new_last = last + counters[i];
    counters[i] = last;
    last = new_last;
  }
  int32_t* res = new int32_t[m];
  for (int32_t i = 0; i < m; i++) {
    res[counters[classes[suf_array[i]]]++] = suf_array[i];
  }
  for (int32_t i = 0; i < m; i++) {
    suf_array[i] = res[i];
  }
  delete[] res;
  delete[] counters;
}
void build_suf_array() {
  str.push_back('a' - 1);
  int32_t m = str.size();
  suf_array = new int32_t[m];
  int32_t* classes = new int32_t[str.size()];
  int32_t counters[30];
  for (int32_t i = 0; i < 30; i++) counters[i] = 0;
  for (int32_t i = 0; i < m; i++) counters[str[i] - 'a' + 1]++;
  int32_t starts[30];
  starts[0] = 0;
  for (int32_t i = 1; i < 30; i++) starts[i] = starts[i - 1] + counters[i - 1];
  int32_t* first_symbols = new int32_t[m];
  for (int32_t i = 0; i < m; i++) first_symbols[starts[str[i] - 'a' + 1]++] = i;
  classes[first_symbols[0]] = 0;
  int32_t remains = counters[0] - 1, char_passed = 1;
  for (int32_t i = 1; i < m; i++)
    if (remains == 0) {
      classes[first_symbols[i]] = classes[first_symbols[i - 1]] + 1;
      remains = counters[char_passed++] - 1;
      while (remains < 0) remains = counters[char_passed++] - 1;
    } else {
      classes[first_symbols[i]] = classes[first_symbols[i - 1]];
      remains--;
    }
  for (int32_t i = 0; i < m; i++) suf_array[i] = first_symbols[i];
  int32_t length = 1;
  int32_t* new_classes = new int32_t[m];
  while (classes[m - 1] < str.size() - 1 && length < m) {
    for (int32_t i = 0; i < m; i++) {
      suf_array[i] = (suf_array[i] - length + m) % m;
    }
    radix_sort(classes);
    new_classes[suf_array[0]] = 0;
    for (int32_t i = 1; i < m; i++) {
      std::pair<int32_t, int32_t> prev = {
          classes[suf_array[i - 1]], classes[(suf_array[i - 1] + length) % m]};
      std::pair<int32_t, int32_t> cur = {classes[suf_array[i]],
                                         classes[(suf_array[i] + length) % m]};
      if (prev == cur)
        new_classes[suf_array[i]] = new_classes[suf_array[i - 1]];
      else
        new_classes[suf_array[i]] = new_classes[suf_array[i - 1]] + 1;
    }
    int32_t* tmp = classes;
    classes = new_classes;
    new_classes = tmp;
    length *= 2;
  }
  inverse_suf_array = new int32_t[m];
  for (int32_t i = 0; i < m; i++) inverse_suf_array[suf_array[i]] = i;
}
void solve() {
  std::cin >> n;
  std::cin >> str;
  build_suf_array();
  int32_t* lcp = new int32_t[str.size()];
  int32_t last = 0;
  for (int32_t i = 0; i < str.size() - 1; i++) {
    lcp[inverse_suf_array[i] - 1] = last;
    while (i + lcp[inverse_suf_array[i] - 1] < str.size() &&
           str[i + lcp[inverse_suf_array[i] - 1]] ==
               str[suf_array[inverse_suf_array[i] - 1] +
                   lcp[inverse_suf_array[i] - 1]])
      lcp[inverse_suf_array[i] - 1]++;
    last = std::max(0, lcp[inverse_suf_array[i] - 1] - 1);
  }
  int32_t** lcp_real = new int32_t*[n + 1];
  for (int32_t i = 0; i < n + 1; i++) {
    lcp_real[i] = new int32_t[n + 1];
    lcp_real[i][i] = INT32_MAX;
    for (int32_t j = i + 1; j < n + 1; j++)
      lcp_real[i][j] = std::min(lcp_real[i][j - 1], lcp[j - 1]);
  }
  int32_t* rev_suf_array = new int32_t[n];
  for (int32_t i = 1; i <= n; i++) rev_suf_array[suf_array[i]] = i - 1;
  int32_t* dp = new int32_t[n];
  dp[0] = n;
  for (int32_t i = 1; i < n; i++) {
    dp[i] = n - i;
    for (int32_t j = 0; j < i; j++)
      if (rev_suf_array[j] < rev_suf_array[i])
        dp[i] = std::max(
            dp[i], dp[j] + n - i -
                       lcp_real[inverse_suf_array[j]][inverse_suf_array[i]]);
  }
  int32_t answer = 0;
  for (int32_t i = 0; i < n; i++) answer = std::max(answer, dp[i]);
  std::cout << answer << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int32_t num_tests;
  std::cin >> num_tests;
  for (int32_t t = 0; t < num_tests; t++) {
    solve();
  }
  return 0;
}
