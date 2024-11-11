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
set<long long int> s[10];
bool compare1(pair<long long int, long long int>& a,
              pair<long long int, long long int>& b) {
  if (a.first != b.first) return a.first < b.first;
  return a.second > b.second;
}
bool compare2(pair<long long int, long long int>& a,
              pair<long long int, long long int>& b) {
  if (a.first != b.first) return a.first < b.first;
  return a.second < b.second;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int n, i, j, x, k, y, m, w, h, c, l, b, f, T, a, t, u, v, r, A, B;
  cin >> n >> k;
  long long int arr[n + 1];
  vector<long long int> vec;
  set<long long int> s;
  for (i = 1; i <= n; i++) {
    cin >> arr[i];
    if (arr[i] == 0) {
      vec.push_back(i);
      s.insert(i);
    }
  }
  for (i = 1; i <= n; i++) {
    if (s.find(i) == s.end()) {
      long long int val = i + k;
      long long int count = 0;
      for (j = 0; j < vec.size(); j++) {
        if (count == arr[i]) break;
        if (vec[j] >= val) {
          count++;
        }
      }
      while (j < vec.size() && vec[j] < i) j++;
      vec.insert(vec.begin() + j, i);
    }
  }
  for (i = 1; i <= n; i++) {
    long long int ind;
    long long int count = 0;
    long long int val = i + k;
    for (j = 0; j < vec.size(); j++) {
      if (vec[j] == i) {
        ind = j;
        break;
      }
    }
    for (j = 0; j < vec.size(); j++) {
      if (count == arr[i]) break;
      if (vec[j] >= val) count++;
    }
    while (j < ind && vec[j] < vec[ind]) {
      j++;
    }
    if (j < ind) {
      for (l = ind; l > j; l--) {
        vec[l] = vec[l - 1];
      }
      vec[j] = i;
    }
  }
  for (j = 0; j < vec.size(); j++) {
    cout << vec[j] << " ";
  }
}
