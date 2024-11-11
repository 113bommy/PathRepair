#include <bits/stdc++.h>
int main() {
  int32_t num_samples, n;
  std::cin >> num_samples >> n;
  std::string* samples = new std::string[num_samples];
  for (int32_t i = 0; i < num_samples; i++) std::cin >> samples[i];
  int32_t count1[26];
  bool has_repetitions = false;
  for (int32_t i = 0; i < 26; i++) count1[i] = 0;
  for (int32_t i = 0; i < n; i++) count1[samples[0][i] - 'a']++;
  for (int32_t i = 0; i < 26; i++)
    has_repetitions = has_repetitions || count1[i] > 1;
  int32_t count2[26];
  for (int32_t i = 0; i < num_samples; i++) {
    for (int32_t j = 0; j < 26; j++) count2[j] = 0;
    for (int32_t j = 0; j < n; j++) count2[samples[i][j] - 'a']++;
    for (int32_t j = 0; j < 26; j++)
      if (count1[j] != count2[j]) {
        std::cout << -1;
        return 0;
      }
  }
  bool** comp_table = new bool*[num_samples];
  int32_t* num_matching = new int32_t[num_samples];
  for (int32_t i = 0; i < num_samples; i++) {
    comp_table[i] = new bool[n];
    num_matching[i] = 0;
    for (int32_t j = 0; j < n; j++) {
      comp_table[i][j] = samples[i][j] == samples[0][j];
      if (comp_table[i][j]) num_matching[i]++;
    }
  }
  for (int32_t i = 0; i < n; i++)
    for (int32_t j = i + 1; j < n; j++) {
      char tmp = samples[0][i];
      samples[0][i] = samples[0][j];
      samples[0][j] = tmp;
      bool ok = true;
      for (int32_t k = 1; k < num_samples; k++) {
        int32_t num_unmatched = n - num_matching[k];
        if (comp_table[k][i]) num_unmatched++;
        if (comp_table[k][j]) num_unmatched++;
        if (samples[k][i] == samples[0][i]) num_unmatched--;
        if (samples[k][j] == samples[0][j]) num_unmatched--;
        if (!((num_unmatched == 0 && has_repetitions) || num_unmatched == 2)) {
          ok = false;
          break;
        }
      }
      if (ok) {
        std::cout << samples[0];
        return 0;
      }
      tmp = samples[0][i];
      samples[0][i] = samples[0][j];
      samples[0][j] = tmp;
    }
  std::cout << -1;
  return 0;
}
