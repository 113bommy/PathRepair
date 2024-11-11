#include <bits/stdc++.h>
using namespace std;
const int MAXH = 1010;
int n, k;
vector<int> arr;
vector<int> ans;
int best = -1, bestS0 = 0;
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  for (int s0 = 1; s0 < MAXH; s0++) {
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] == s0 + k * i) {
        res++;
      }
    }
    if (res > best) {
      best = res;
      bestS0 = s0;
    }
  }
  cout << (n - best) << endl;
  for (int i = 0; i < n; i++) {
    int d = (bestS0 + i * k) - arr[i];
    if (d != 0) {
      if (d > 0)
        cout << "+ ";
      else
        cout << "- ";
      cout << (i + 1) << " ";
      cout << abs(d) << endl;
    }
  }
  return 0;
}
