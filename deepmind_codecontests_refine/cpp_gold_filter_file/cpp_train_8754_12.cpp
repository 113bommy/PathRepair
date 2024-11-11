#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  srand(time(NULL));
  long long n, k;
  cin >> n >> k;
  long long l, r, c;
  string answer;
  l = 1;
  r = n;
  while (true) {
    if (r - l + 1 > 4 * k) {
      c = (l + r) / 2;
      cout << l << " " << c << "\n";
      cout.flush();
      cin >> answer;
      if (answer == "Bad") return 0;
      if (answer == "Yes") {
        if (l == c) return 0;
        l = l - k;
        r = c + k;
        if (l < 1) l = 1;
        if (r > n) r = n;
      } else {
        if (k == 0 && r == c + 1) {
          cout << r << " " << r << "\n";
          cout.flush();
          return 0;
        }
        l = c - k + 1;
        r = r + k;
        if (l < 1) l = 1;
        if (r > n) r = n;
      }
    } else {
      long long i = (rand() % (r - l + 1)) + l;
      cout << i << " " << i << "\n";
      cout.flush();
      cin >> answer;
      if (answer == "Bad") return 0;
      if (answer == "Yes") {
        return 0;
      }
      l = l - k;
      r = r + k;
      if (l < 1) l = 1;
      if (r > n) r = n;
    }
  }
}
