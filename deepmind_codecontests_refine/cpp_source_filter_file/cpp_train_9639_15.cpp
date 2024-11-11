#include <bits/stdc++.h>
using namespace std;
bool isprime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
struct compare {
  inline bool operator()(const std::string& first,
                         const std::string& second) const {
    return first.size() < second.size();
  }
};
int main() {
  long long int n, m;
  cin >> n >> m;
  long long int x = 1;
  while (1) {
    if (x % 2 != 0) {
      if (n >= 2 && m >= 2) {
        n = n - 2;
        m = m - 2;
      } else if (n == 1 && m >= 12) {
        m = m - 12;
        n = n - 1;
      } else if (n == 0 && m >= 22) {
        m = m - 22;
      } else {
        cout << "Hanako";
        break;
      }
      x++;
    }
    if (x % 2 == 0) {
      if (n == 0 && m >= 22) {
        m = m - 22;
      } else if (n == 1 && m >= 12) {
        m = m - 12;
        n = n - 1;
      } else if (n >= 2 && m >= 2) {
        n = n - 2;
        m = m - 2;
      } else {
        cout << "Ciel" << endl;
        break;
      }
      x++;
    }
  }
}
