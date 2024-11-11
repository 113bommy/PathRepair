#include <bits/stdc++.h>
using namespace std;
long long int fn(long long int a, long long int b) {
  if (a % b) return 1 + a / b;
  return a / b;
}
int main() {
  long long int n;
  string s, t;
  cin >> n >> s >> t;
  long long int fa = 0, fb = 0, a_in_s = 0, i;
  for (i = 0; i < n; i++) {
    if (s[i] == 'a') fa++;
    if (t[i] == 'a') fa++;
    if (s[i] == 'b') fb++;
    if (t[i] == 'b') fb++;
    if (s[i] == 'a') a_in_s++;
  }
  if (fa % 2 || fb % 2) {
    cout << -1;
    exit(0);
  }
  vector<long long int> ab, ba;
  for (i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      if (s[i] == 'a')
        ab.push_back(i);
      else
        ba.push_back(i);
    }
  }
  long long int mis_mtch = ab.size() + ba.size();
  mis_mtch -= abs((fa / 2 - a_in_s));
  if (ab.size() > ba.size()) {
    long long int sz = ab.size() - ba.size(), szz = ba.size();
    i = 0;
    long long int temp = 0;
    if (szz % 2) {
      temp = 2;
    }
    cout << (a_in_s - fa / 2) + 2 * (szz / 2) + temp << "\n";
    for (i = 0; i < sz; i += 2) {
      cout << ab[i] + 1 << " " << ab[i + 1] + 1 << "\n";
    }
    if (szz % 2) {
      cout << ab[i] + 1 << " " << ab[i] + 1 << "\n"
           << ab[i] + 1 << " " << ba[i - sz] + 1 << "\n";
      i++;
    }
    for (; i < ab.size(); i += 2) {
      cout << ab[i] + 1 << " " << ab[i + 1] + 1 << "\n"
           << ba[i - sz] + 1 << " " << ba[i + 1 - sz] + 1 << "\n";
    }
  }
  if (ba.size() >= ab.size()) {
    long long int sz = ba.size() - ab.size(), szz = ab.size();
    i = 0;
    long long int temp = 0;
    if (szz % 2) temp = 2;
    cout << -1 * (a_in_s - fa / 2) + 2 * (szz / 2) + temp << "\n";
    for (i = 0; i < sz; i += 2) {
      cout << ba[i] + 1 << " " << ba[i + 1] + 1 << "\n";
    }
    if (szz % 2) {
      cout << ba[i] + 1 << " " << ba[i] + 1 << "\n"
           << ba[i] + 1 << " " << ab[i - sz] + 1 << "\n";
      i++;
    }
    for (; i < ba.size(); i += 2) {
      cout << ba[i] + 1 << " " << ba[i + 1] + 1 << "\n"
           << ab[i - sz] + 1 << " " << ab[i - sz + 1] + 1 << "\n";
    }
  }
}
