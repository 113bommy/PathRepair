#include <bits/stdc++.h>
int n;
bool a[100];
int count = 0;
int count2 = 0;
int max = -1000;
int main() {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    if (a[i]) count2++;
  }
  for (int i = 0; i < n; i++) {
    count = 0;
    for (int j = i; j < n; j++) {
      if (a[j])
        count--;
      else
        count++;
      max = std::max(max, count);
    }
  }
  std::cout << max + count2;
}
