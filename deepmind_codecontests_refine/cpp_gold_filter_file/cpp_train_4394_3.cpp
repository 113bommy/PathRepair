#include <bits/stdc++.h>
using namespace std;
char flip(char a) {
  if (a == 'W')
    return 'B';
  else
    return 'W';
}
long long int mod(long long int a, long long int n) {
  if (a < 0) a += n;
  return a % n;
}
int main() {
  long long int n;
  long long int k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<pair<long long int, long long int> > arr;
  bool bo = false;
  int start = -1;
  for (long long int i = 0; i < n; i++) {
    if (s[(i + 1) % n] != s[i] and s[mod((i - 1), n)] != s[i]) {
      if (!bo) {
        bo = true;
        start = i;
      }
    } else {
      if (bo) {
        arr.push_back(make_pair(start, i));
        bo = false;
      }
    }
  }
  if (bo) {
    if ((int)arr.size() != 0) {
      if (arr[0].first == 0) arr[0].first = start;
    } else
      arr.push_back(make_pair(start, n));
  }
  if ((int)arr.size() == 1 and arr[0].first == 0 and arr[0].second == n) {
    if (k % 2 == 0) {
      cout << s;
      return 0;
    } else {
      for (long long int i = 0; i < n; i++) {
        s[i] = flip(s[i]);
      }
      cout << s;
      return 0;
    }
  }
  long long int store;
  for (long long int i = 0; i < (int)arr.size(); i++) {
    if (arr[i].second - arr[i].first > 0)
      store = arr[i].second - arr[i].first;
    else
      store = arr[i].second + n - arr[i].first;
    for (long long int j = 0; j < min((store + 1) / 2, k); j++) {
      s[(arr[i].first + j) % n] = s[mod(arr[i].first - 1, n)];
      s[mod(arr[i].second - 1 - j, n)] = s[arr[i].second % n];
    }
    if (k < (store + 1) / 2 and k % 2 == 1) {
      for (long long int j = 0; j < store - 2 * k; j++) {
        s[(arr[i].first + k + j) % n] = flip(s[(arr[i].first + k + j) % n]);
      }
    }
  }
  cout << s;
}
