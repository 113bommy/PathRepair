#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> hash(105, 0);
  vector<int> index_hash(105, 0);
  int n, k;
  cin >> n >> k;
  int temp;
  for (int i = 1; i <= n; i++) {
    cin >> temp;
    if (hash[temp] == 0) {
      index_hash[temp] = i;
    }
    hash[temp] = 1;
  }
  cout << endl;
  int count = 0;
  for (int i = 0; i < hash.size(); i++) {
    if (hash[i] > 0) {
      count += 1;
    }
  }
  vector<int> index;
  if (count >= k) {
    cout << "YES" << endl;
    for (int i = hash.size() - 1; i >= 0 && k > 0; i--) {
      if (hash[i] > 0) {
        index.push_back(index_hash[i]);
        k--;
      }
    }
  } else {
    cout << "NO" << endl;
    return 0;
  }
  sort(index.begin(), index.end());
  for (int i = 0; i < index.size(); i++) {
    cout << index[i] << " ";
  }
  cout << endl;
  return 0;
}
