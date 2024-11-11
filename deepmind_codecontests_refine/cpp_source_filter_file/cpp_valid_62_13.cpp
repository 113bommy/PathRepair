#include <bits/stdc++.h>
int main() {
  int t;
  std::cin >> t;
  while (t) {
    int n;
    std::cin >> n;
    int arr[n];
    for (auto &x : arr) std::cin >> x;
    if (n + 1 == 2) {
      if (arr[0] == 0)
        std::cout << "1 2" << std::endl;
      else
        std::cout << "2 1" << std::endl;
    } else {
      if (arr[n - 1] == 0) {
        for (int i = 1; i <= n + 1; i++) std::cout << i << " ";
        std::cout << std::endl;
      } else if (arr[0] == 1) {
        std::cout << n + 1 << " ";
        for (int i = 1; i <= n; i++) std::cout << i << " ";
        std::cout << std::endl;
      } else {
        int turnaround = -1;
        for (int i = 0; i <= n - 3; i++) {
          if (arr[i] == 0 && arr[i + 1] == 1) {
            turnaround = i;
            break;
          }
        }
        if (turnaround == -1)
          std::cout << "-1" << std::endl;
        else {
          for (int i = 0; i <= turnaround; i++) {
            std::cout << i + 1 << " ";
          }
          std::cout << n + 1 << " ";
          for (int i = turnaround + 1; i < n; i++) std::cout << i + 1 << " ";
          std::cout << std::endl;
        }
      }
    }
    t--;
  }
}
