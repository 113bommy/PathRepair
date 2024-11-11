#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int long long MAX_SIZE = 1000006;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(6);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> v;
    string x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      v.push_back(x);
    }
    vector<vector<int>> count(n, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
      string temp = v[i];
      for (int j = 0; j < temp.length(); j++) count[i][temp[j] - 'a']++;
    }
    vector<int> freq(26);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 26; j++) freq[j] += count[i][j];
    }
    int k = 0;
    for (int i = 0; i < 26; i++) {
      if (freq[i] % n) k = 1;
    }
    if (k == 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
