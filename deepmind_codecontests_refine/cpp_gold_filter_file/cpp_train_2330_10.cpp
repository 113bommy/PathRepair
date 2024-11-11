#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, t;
  cin >> n >> t;
  vector<int> v;
  int temp;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    v.push_back(temp);
  }
  int a = 0, b = 0;
  int sum = 0;
  bool whole = false;
  while (true) {
    if (b == n) {
      whole = true;
      break;
    }
    sum += v[b];
    if (sum > t) {
      sum -= v[b];
      break;
    }
    b++;
  }
  if (!whole) {
    int cursum = sum;
    int max = b - a;
    int curnum = max;
    for (int i = 1; i < n; ++i) {
      cursum -= v[i - 1];
      curnum--;
      while (true) {
        if (b == n) {
          break;
        }
        cursum += v[b];
        if (cursum <= t) {
          b++;
          curnum++;
        } else {
          cursum -= v[b];
          break;
        }
      }
      if (curnum > max) max = curnum;
    }
    cout << max << '\n';
  } else {
    cout << n << '\n';
  }
}
