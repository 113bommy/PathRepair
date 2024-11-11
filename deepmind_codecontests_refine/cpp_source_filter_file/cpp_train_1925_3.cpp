#include <bits/stdc++.h>
using namespace std;
long long int max(long long int a, long long int b) {
  if (a > b)
    return a;
  else
    return b;
}
long long int min(long long int a, long long int b) {
  if (a < b)
    return a;
  else
    return b;
}
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int i, j, k, x, y, t, e, n, d, m, z;
  cin >> n;
  long long int arr1[n];
  long long int arr2[n];
  for (i = 0; i < n; i++) {
    cin >> arr1[i];
  }
  for (i = 0; i < n; i++) {
    cin >> arr2[i];
  }
  vector<pair<long long int, long long int> > vec;
  for (i = 0; i < n; i++) {
    if (arr2[i] == arr1[i]) continue;
    j = i;
    while (arr2[j] != arr1[i]) {
      j++;
    }
    for (j = j; j > i; j--) {
      swap(arr2[j], arr2[j - 1]);
      vec.push_back(make_pair(j, j - 1));
    }
  }
  cout << vec.size() << "\n";
  for (i = 0; i < vec.size(); i++) {
    cout << vec[i].first + 1 << " " << vec[i].second + 1 << "\n";
  }
}
