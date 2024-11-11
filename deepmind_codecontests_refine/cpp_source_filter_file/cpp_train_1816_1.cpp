#include <bits/stdc++.h>
using namespace std;
int binarna(vector<int> a, int k) {
  int n = a.size();
  int low = 0, high = n - 1;
  bool b;
  int mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (a[mid] == k) {
      b = true;
      break;
    }
    if (k < a[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }
  if (b)
    return mid;
  else
    return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  string s;
  cin >> s;
  string v = "AHIMNOTUVWXY";
  for (int i = 0; i < s.length(); ++i) {
    bool b = false;
    for (int j = 0; j < v.length(); ++j) {
      if (s[i] == v[j]) b = true;
    }
    if (b == false) return cout << "NO", 0;
  }
  string a = s;
  reverse(a.begin(), a.end());
  if (a == s)
    cout << "YES";
  else
    cout << "NO";
}
