#include <bits/stdc++.h>
using namespace std;
unsigned long long inv = 0;
vector<int> merge(const vector<int> &arr1, const vector<int> &arr2) {
  vector<int> res(arr1.size() + arr2.size());
  int i = 0, j = 0, k = 0;
  while (i < arr1.size() && j < arr2.size()) {
    if (arr1[i] < arr2[j]) {
      res[k++] = arr1[i++];
    } else {
      inv += arr1.size() - i;
      res[k++] = arr2[j++];
    }
  }
  while (i < arr1.size()) res[k++] = arr1[i++];
  while (j < arr2.size()) res[k++] = arr2[j++];
  return res;
}
vector<int> merge_sort(const vector<int> &arr, int s, int e) {
  if (s == e) {
    vector<int> res(1);
    res[0] = arr[s];
    return res;
  } else if (e < s) {
    return vector<int>();
  }
  int mid = (s + e) / 2;
  return merge(merge_sort(arr, s, mid), merge_sort(arr, mid + 1, e));
}
int main() {
  int n;
  cin >> n;
  map<int, int> swaps;
  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    int temp = swaps.count(a) ? swaps[a] : a;
    swaps[a] = swaps.count(b) ? swaps[b] : b;
    swaps[b] = temp;
  }
  vector<int> arr;
  for (map<int, int>::iterator it = swaps.begin(); it != swaps.end(); it++) {
    arr.push_back(it->second);
  }
  vector<int> sorted = merge_sort(arr, 0, arr.size() - 1);
  for (map<int, int>::iterator it = swaps.begin(); it != swaps.end(); it++) {
    int cur_pos = it->first;
    int orig_pos = it->second;
    if (cur_pos == orig_pos) continue;
    long long m = abs(orig_pos - cur_pos) - 1;
    int a = cur_pos, b = orig_pos;
    if (a > b) swap(a, b);
    int low = lower_bound(sorted.begin(), sorted.end(), a) - sorted.begin();
    int up = lower_bound(sorted.begin(), sorted.end(), b) - sorted.begin();
    m -= up - low - 1;
    inv += m;
  }
  cout << inv;
}
