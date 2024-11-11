#include <bits/stdc++.h>
using namespace std;
long long arr[200500], pos[200500];
int l[200500], r[200500];
int main() {
  int n;
  cin >> n;
  vector<int> vec;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
    l[i] = -1;
    r[i] = n;
  }
  for (int i = 0; i < n; i++) {
    if (!vec.empty()) {
      while (!vec.empty()) {
        int x = vec[vec.size() - 1];
        if (arr[x] >= arr[i])
          vec.pop_back();
        else
          break;
      }
    }
    if (!vec.empty()) l[i] = vec[vec.size() - 1];
    vec.push_back(i);
  }
  while (!vec.empty()) vec.pop_back();
  for (int i = n - 1; i >= 0; i--) {
    if (!vec.empty()) {
      while (!vec.empty()) {
        int x = vec[vec.size() - 1];
        if (arr[x] >= arr[i])
          vec.pop_back();
        else
          break;
      }
    }
    if (!vec.empty()) r[i] = vec[vec.size() - 1];
    vec.push_back(i);
  }
  for (int i = 0; i < n; i++) {
    int x = r[i] - l[i] - 1;
    pos[x] = max(pos[x], arr[i]);
  }
  for (int i = 1; i < n; i++) pos[i] = max(pos[i], pos[i + 1]);
  for (int i = 1; i <= n; i++) printf("%lld ", pos[i]);
  return 0;
}
