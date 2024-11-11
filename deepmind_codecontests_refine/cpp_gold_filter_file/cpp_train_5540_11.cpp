#include <bits/stdc++.h>
using namespace std;
long long mini(long long a, long long b) {
  if (a < b) return a;
  return b;
}
long long maxi(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long mod(long long a) { return a % 1000010; }
long long power(long long a, long long b) {
  if (b == 0)
    return 1;
  else if (b % 2 == 0)
    return power(a * a, b / 2);
  else
    return a * power(a * a, b / 2);
}
long long powermod(long long a, long long b) {
  if (b == 0)
    return 1;
  else if (b % 2 == 0)
    return mod(powermod(mod(a * a), b / 2));
  else
    return mod(a) * mod(powermod(mod(a * a), b / 2));
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
int prefix_length[1000010];
int cnt[1000010];
void prefix_string(string s) {
  prefix_length[0] = -1;
  int k = -1;
  for (int i = 1; i < s.length(); i++) {
    k = prefix_length[i - 1];
    while (k >= 0 && s[k + 1] != s[i]) {
      k = prefix_length[k];
    }
    if (s[k + 1] == s[i]) k++;
    prefix_length[i] = k;
    if (k > -1) cnt[k]++;
  }
}
int main() {
  string s;
  cin >> s;
  prefix_string(s);
  int k = prefix_length[s.length() - 1];
  if (k > -1 && cnt[k] >= 2) {
    cout << s.substr(0, k + 1) << endl;
    return 0;
  } else {
    if (k == -1 || prefix_length[k] == -1)
      cout << "Just a legend" << endl;
    else
      cout << s.substr(0, prefix_length[k] + 1) << endl;
  }
  return 0;
}
