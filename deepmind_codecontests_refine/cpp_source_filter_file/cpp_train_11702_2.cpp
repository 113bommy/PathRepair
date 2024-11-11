#include <bits/stdc++.h>
using namespace std;
vector<int> temp(100005);
vector<int> v(100005);
int fn(int l, int h, int x) {
  while (h - l > 1) {
    int mid = (h + l) / 2;
    if (temp[mid] < x) {
      l = mid + 1;
    } else {
      h = mid;
    }
  }
  if (temp[h] > x)
    return h;
  else
    return l;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int len = 1;
  temp[0] = v[0];
  for (int i = 1; i < n; i++) {
    if (temp[0] > v[i]) {
      temp[0] = v[i];
    } else if (v[i] > temp[len - 1]) {
      temp[len] = v[i];
      len++;
    } else {
      int index = fn(0, len - 1, v[i]);
      temp[index] = v[i];
    }
  }
  cout << len;
}
