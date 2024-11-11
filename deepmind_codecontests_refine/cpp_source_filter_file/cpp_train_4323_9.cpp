#include <bits/stdc++.h>
int main() {
  unsigned n;
  scanf("%d", &n);
  std::vector<int> output;
  for (int i = 30; i >= 0; --i)
    if (n & (1 << i)) output.push_back(1 << i);
  for (std::size_t i = 0; i < output.size(); ++i) {
    if (i != output.size() - 1)
      printf("%d ", output[i]);
    else
      printf("%d\n", output[i]);
  }
  exit(0);
}
