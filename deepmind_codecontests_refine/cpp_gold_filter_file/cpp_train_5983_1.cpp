#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic ignored "-Wformat"
template <typename T>
void printContainer(T& a) {
  auto it = a.begin();
  cout << "{" << *(it++);
  for (; it != a.end(); ++it) cout << ", " << (*it);
  cout << "}\n";
}
int main() {
  ios::sync_with_stdio(false);
  int n, p;
  cin >> n >> p;
  --p;
  char c;
  vector<int> nums;
  for (int i = 0; i < (int)(n); ++i) {
    cin >> c;
    nums.push_back(c - 'a');
  }
  if (p >= n / 2) p = n - 1 - p;
  int L = p, R = p;
  int total = 0;
  for (int at = 0; at < (int)(n / 2); ++at) {
    int cl = nums[at], cr = nums[n - 1 - at];
    if (cl != cr) {
      if (cl > cr) swap(cl, cr);
      total += min(cr - cl, 26 + cl - cr);
      L = min(L, at);
      R = max(L, at);
    }
  }
  if (L >= p) {
    total += R - p;
  } else if (R <= p) {
    total += p - L;
  } else {
    total += min(2 * (R - p) + p - L, 2 * (p - L) + R - p);
  }
  cout << total << endl;
}
