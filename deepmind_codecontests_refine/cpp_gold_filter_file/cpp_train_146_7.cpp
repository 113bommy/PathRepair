#include <bits/stdc++.h>
using namespace std;
bool binary(vector<int> v, int key) {
  int lo = 0, hi = v.size() - 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (v[mid] == key)
      return true;
    else if (v[mid] < key)
      lo = mid + 1;
    else
      hi = mid - 1;
  }
  return false;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first)
    return a.second > b.second;
  else
    return a.first < b.first;
}
long long fact(long long n) {
  if (n == 1 || n == 0)
    return 1;
  else
    return n * fact(n - 1);
}
set<string> b;
void permutations(string str, int i, int n) {
  if (i == n - 1) {
    b.insert(str);
    return;
  }
  for (int j = i; j < n; j++) {
    swap(str[i], str[j]);
    permutations(str, i + 1, n);
    swap(str[i], str[j]);
  }
}
bool compp(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second > b.second;
}
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  if (v[0] == v[n - 1]) {
    if (v.size() % 2 == 0)
      cout << "YES";
    else
      cout << "NO";
  } else {
    int n100 = 0, n200 = 0;
    for (int i : v) i == 100 ? n100++ : n200++;
    if (n100 % 2 == 0)
      cout << "YES";
    else
      cout << "NO";
  }
  return 0;
}
