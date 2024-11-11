#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
vector<int> v;
int n;
void calc(long long ind) {
  if (ind > n) return;
  v.push_back(ind);
  calc(ind * 10 + 4);
  calc(ind * 10 + 7);
}
int main() {
  cin >> n;
  calc(0);
  sort(v.begin(), v.end());
  int l = 0, r = v.size() - 1, mid;
  while (l < r) {
    mid = (l + r) / 2;
    if (v[mid] == n) {
      r = mid;
      break;
    } else if (v[mid] > n)
      r = mid - 1;
    else
      l = mid + 1;
  }
  cout << r;
  return 0;
}
