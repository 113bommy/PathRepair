#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  int n, c = 0;
  cin >> n;
  vector<int> arr(n * 2), vec, vec1;
  for (int i = 0; i < n * 2; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end(), greater<int>());
  for (int i = 0, j = (2 * n) - 1; i < n; i++, j--) {
    vec.push_back(arr[i]);
    vec1.push_back(arr[j]);
  }
  for (int i = 0; i < vec.size(); i++) {
    for (int j = 0; j < vec1.size(); j++) {
      if (vec[i] > vec1[j]) {
        c++;
      }
    }
  }
  if (c == n * n) {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}
