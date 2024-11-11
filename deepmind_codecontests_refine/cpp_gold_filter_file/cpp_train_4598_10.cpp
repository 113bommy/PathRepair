#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, x, i, j;
  cin >> n >> x;
  vector<long long> arr(n);
  vector<pair<long long, long long>> A(n);
  bool ascending = true;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
    A[i] = {arr[i], i};
    if (i > 0) {
      ascending = ascending & (arr[i] >= arr[i - 1]);
    }
  }
  if (ascending) {
    cout << (x * (x + 1)) / 2;
  } else {
    sort(A.begin(), A.end());
    long long r, l;
    l = 0;
    r = A.size() - 1;
    while ((r > 0) && (A[r].second > A[r - 1].second)) {
      r--;
    }
    while ((l < A.size() - 2) && (A[l].second < A[l + 1].second)) {
      l++;
    }
    vector<long long> indices(l + 1);
    for (long long itr = 0; itr <= l; itr++) {
      indices[itr] = A[itr].second;
    }
    long long temp;
    long long ans = 0;
    while (r <= A.size()) {
      if (r != A.size()) {
        temp = (lower_bound(indices.begin(), indices.end(), A[r].second) -
                indices.begin()) -
               1;
        ans += (A[temp + 1].first) * (A[r].first - A[r - 1].first);
      } else {
        ans += (A[l + 1].first * (x - A[r - 1].first + 1));
      }
      r++;
    }
    cout << ans;
  }
  return 0;
}
