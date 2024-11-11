#include <bits/stdc++.h>
using namespace std;
struct stop {
  long long exit;
  long long enter;
};
bool check(int y) {
  vector<int> v;
  while (y != 0) {
    v.push_back(y % 10);
    y = y / 10;
  }
  for (long long i = 0; i < v.size(); i++) {
    for (long long j = i + 1; j < v.size(); j++) {
      if (v[i] == v[j]) {
        return 0;
      }
    }
  }
  return 1;
}
long long max_non_dec(long long a[100000], long long n) {
  long long maxlen = 0;
  long long len = 0;
  for (long long i = 1; i < n; i++) {
    if (a[i] >= a[i - 1]) {
      len++;
    } else {
      maxlen = max(maxlen, len);
      len = 0;
    }
  }
  maxlen = max(maxlen, len);
  return maxlen + 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s[100000];
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (long long i = 0; i < n; i++) {
    if (s[i] == "1") {
      cout << "HARD";
      return 0;
    }
  }
  cout << "EASY";
  return 0;
}
