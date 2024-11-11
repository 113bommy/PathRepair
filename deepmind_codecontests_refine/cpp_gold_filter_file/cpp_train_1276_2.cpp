#include <bits/stdc++.h>
using namespace std;
const int n1 = 1e9 + 7;
struct compare {
  inline bool operator()(const std::string& first,
                         const std::string& second) const {
    return first.size() < second.size();
  }
};
long long fact(long long n) {
  long long ans = 1;
  for (long long i = 1; i < n + 1; i++) {
    ans = ((ans % n1) * (i % n1)) % n1;
  }
  return ans;
}
string str;
int count_ch(int l, int r, char ch) {
  int cnt = 0;
  for (int i = l; i < r + 1; i++) {
    if (str[i] != ch) {
      cnt++;
    }
  }
  return cnt;
}
int solve(int l, int r, char ch) {
  if (l == r) {
    if (str[l] == ch)
      return 0;
    else
      return 1;
  }
  int mid = (l + r) / 2;
  return min(count_ch(l, mid, ch) + solve(mid + 1, r, (char)(ch + 1)),
             count_ch(mid + 1, r, ch) + solve(l, mid, (char)(ch + 1)));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s1;
    cin >> s1;
    str = s1;
    cout << solve(0, n - 1, 'a') << endl;
  }
  return 0;
}
