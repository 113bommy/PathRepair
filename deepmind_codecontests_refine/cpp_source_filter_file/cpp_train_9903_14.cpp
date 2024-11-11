#include <bits/stdc++.h>
using namespace std;
struct node {
  long long x;
  long long y;
};
bool myfunc(struct node A, struct node B) {
  if (A.x < B.x)
    return true;
  else if (A.x == B.x) {
    return A.y < B.y;
  } else
    return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k;
  cin >> n >> k;
  struct node arr[n];
  vector<long long> v;
  unordered_set<long long> mp;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].x;
  }
  for (int i = 0; i < n; i++) {
    cin >> arr[i].y;
  }
  sort(arr, arr + n, myfunc);
  for (long long i = n - 1; i >= 0; i--) {
    if (mp.find(arr[i].x) == mp.end()) {
      mp.insert(arr[i].x);
    } else {
      v.push_back(arr[i].y);
    }
  }
  long long s = k - v.size();
  long long ans = 0;
  if (v.size() > 0) {
    sort(v.begin(), v.end());
    for (long long i = 0; i < s; i++) {
      ans += v[i];
    }
  }
  cout << ans << "\n";
  return 0;
}
