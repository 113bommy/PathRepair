#include <bits/stdc++.h>
template <typename T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T>
using max_heap = std::priority_queue<T, std::vector<T>, std::less<T>>;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b;
  cin >> a >> b;
  for (int i = 0; i < a; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < b; j++) cout << '#';
      cout << "\n";
    } else if (i % 4 == 3) {
      cout << '#';
      for (int j = 1; j < b; j++) cout << '.';
      cout << "\n";
    } else {
      for (int j = 0; j < b - 1; j++) cout << '.';
      cout << '#' << "\n";
    }
  }
  return 0;
}
