#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<string, long long int> &a,
               const pair<string, long long int> &b) {
  return (a.second < b.second);
}
bool isPalindrome(string sp) {
  long long int n = sp.size();
  for (long long int k = 0; k < n; k++) {
    long long int i = n - k - 1;
    if (sp[k] != sp[i]) return false;
  }
  return true;
}
string ok(string s, long long int k) {
  long long int n = s.size();
  string ans = "";
  for (long long int i = 0; i < k; i++) {
    ans += (char)(s[i % n]);
  }
  return ans;
}
void solve() {
  long long int n;
  cin >> n;
  long long int arr[3001];
  for (long long int i = 1; i <= n; i++) {
    long long int a;
    cin >> a;
    arr[a] = 1;
  }
  for (long long int i = 1; i < 3001; i++) {
    if (arr[i] == 0) {
      cout << i;
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
