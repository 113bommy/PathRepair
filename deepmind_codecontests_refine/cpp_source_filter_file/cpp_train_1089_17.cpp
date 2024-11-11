#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long GetSteps(long long h, long long n) {
    vector<long long> num_of_steps;
    long long ans = 0;
    num_of_steps.push_back(0);
    num_of_steps.push_back(4);
    for (int i = 2; i <= h; i++) {
      long long temp = num_of_steps[i - 1] + num_of_steps[i - 1] + (long long)4;
      num_of_steps.push_back(temp);
    }
    int p = 0;
    while (n > 0) {
      h--;
      if (h == 1) {
        if (p == 0) {
          ans++;
          if (n == 2) {
            ans++;
          }
        } else {
          ans++;
          if (n == 1) {
            ans++;
          }
        }
        break;
      }
      if (p == 0) {
        ans++;
        if (n > (long long)(1) << h) {
          ans += num_of_steps[h];
          ans++;
          n -= (long long)(1) << h;
          p ^= 1;
        }
      } else {
        ans++;
        if (n <= (long long)(1) << h) {
          ans += num_of_steps[h];
          n--;
          p ^= 1;
        } else {
          n -= (long long)1 << h;
        }
      }
      p ^= 1;
    }
    return ans;
  }
};
int main() {
  long long h, n;
  cin >> h >> n;
  Solution aa;
  cout << aa.GetSteps(h, n) << endl;
  return 0;
}
