#include <bits/stdc++.h>
bool comp(int a, int b) { return a > b; }
int main() {
  long n, k;
  std::cin >> n >> k;
  std::string cards;
  std::cin >> cards;
  long long freq[26] = {0};
  long long val = 0;
  for (auto ch : cards) freq[ch - 'A']++;
  std::sort(freq, freq + 26, comp);
  for (int i = 0; i < 26 && k > 0; i++) {
    if (freq[i] >= k) {
      val += k * k;
      k = 0;
    } else {
      val += freq[i] * freq[i];
      k -= freq[i];
    }
  }
  std::cout << val << "\n";
  return 0;
}
