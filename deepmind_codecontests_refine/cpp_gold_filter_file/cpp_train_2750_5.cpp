#include <bits/stdc++.h>
using namespace std;
int main() {
  int *arr;
  int n;
  cin >> n;
  arr = (int *)malloc(sizeof(int) * n);
  int hash[1001] = {0};
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int max = 0;
  for (int i = 0; i < n; i++) {
    hash[arr[i]]++;
  }
  map<int, int> mp;
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (max < hash[arr[i]]) {
      max = hash[arr[i]];
    }
    mp[arr[i]] = hash[arr[i]];
  }
  cout << max << " " << mp.size() << endl;
  return 0;
}
