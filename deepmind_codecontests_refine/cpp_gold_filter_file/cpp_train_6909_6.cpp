#include <bits/stdc++.h>
using namespace std;
bool desc(int a, int b) { return a > b; }
int main() {
  long long n, x;
  cin >> n >> x;
  long long arr[n + 1], mini = 1e10, sp = 0, p = 0;
  vector<long long> v;
  for (long(i) = (0); (i) < (n); (i)++) {
    cin >> arr[i];
    if (mini > arr[i]) {
      mini = arr[i];
    }
  }
  for (long(i) = (0); (i) < (n); (i)++) {
    if (mini == arr[i]) {
      v.push_back(i);
    }
  }
  p = v[v.size() - 1];
  x--;
  for (long(i) = (0); (i) < (v.size()); (i)++) {
    if (v[i] <= x) {
      p = v[i];
    }
  }
  for (long(i) = (0); (i) < (n); (i)++) {
    arr[i] -= (mini);
    sp += (mini);
  }
  if (x == p) {
  } else {
    if (x < p) {
      for (long(i) = (p + 1); (i) < (n); (i)++) {
        sp++;
        arr[i]--;
      }
      for (long(i) = (0); (i) < (x + 1); (i)++) {
        sp++;
        arr[i]--;
      }
    } else {
      for (long(i) = (p + 1); (i) < (x + 1); (i)++) {
        arr[i]--;
        sp++;
      }
    }
  }
  for (long(i) = (0); (i) < (n); (i)++) {
    if (i == p)
      cout << sp << " ";
    else
      cout << arr[i] << " ";
  }
  return 0;
}
