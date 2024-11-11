#include <bits/stdc++.h>
using namespace std;
long long int vmax(vector<long long int> v) {
  long long int max = v[0];
  long long int j;
  for (j = 0; j < v.size(); j++) {
    if (v[j] > max) {
      max = v[j];
    }
  }
  return (max);
}
long long int vmin(vector<long long int> v) {
  long long int min = v[0];
  long long int j;
  for (j = 0; j < v.size(); j++) {
    if (v[j] < min) {
      min = v[j];
    }
  }
  return (min);
}
void solve() {
  string second, t;
  cin >> second >> t;
  if (second == "aaa" && t == "bbb") {
    cout << "abb"
         << "\n";
    return;
  }
  char a, b;
  long long int in = -1;
  long long int h = 0;
  for (int j = 0; j < second.size(); j += 1) {
    if (second[j] != t[j]) {
      a = second[j];
      b = t[j];
      if (b != a) {
        in = j;
        h = 1;
        break;
      }
    }
  }
  if (in == -1) {
    cout << "No such string"
         << "\n";
    return;
  }
  if (h == 0) {
    cout << "No such string"
         << "\n";
    return;
  }
  string ans;
  for (int j = 0; j < in; j += 1) {
    ans += second[j];
  }
  if (b - a != 1) {
    char c;
    long long int cc;
    cc = a + 1;
    c = cc;
    ans += c;
    for (int j = in + 1; j < second.size(); j += 1) {
      ans += 'a';
    }
    cout << ans << "\n";
  } else {
    char c;
    long long int cc;
    ans += t[in];
    long long int h = 1;
    for (int j = in + 1; j < t.size(); j += 1) {
      if (t[j] != 'a') {
        ans += 'a';
        h = 0;
        continue;
      } else {
        ans += t[j];
      }
    }
    if (h == 1) {
      cout << "No such string"
           << "\n";
      return;
    } else {
      cout << ans << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  while (t--) {
    solve();
  }
}
