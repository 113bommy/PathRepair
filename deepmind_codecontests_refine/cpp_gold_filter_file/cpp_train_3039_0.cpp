#include <bits/stdc++.h>
using namespace std;
priority_queue<long long int, vector<long long int>, greater<long long int> > q,
    t;
map<pair<long long int, long long int>, long long int> mp;
vector<long long int> p[150005], v(1005, 0);
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<long long int> p[2];
    long long int o = 0, c = 0, h = 0;
    for (long long int i = 0; i < (k - 1) * 2; i++) {
      if (i % 2 == 0 && s[i] == ')') {
        o = 0;
        c = 0;
        h = i;
        p[0].push_back(i);
        c++;
        i++;
        while (s[i] != '(' && i < n) {
          i++;
        }
        p[1].push_back(i);
        for (long long int g = 0; g < (i - h + 1) / 2; g++) {
          swap(s[i - g], s[h + g]);
        }
        i = h;
      }
      if (i % 2 == 1 && s[i] == '(') {
        o = 0;
        c = 0;
        h = i;
        p[0].push_back(i);
        o++;
        i++;
        while (s[i] != ')' && i < n) {
          i++;
        }
        p[1].push_back(i);
        for (long long int g = 0; g < (i - h + 1) / 2; g++) {
          swap(s[i - g], s[h + g]);
        }
        i = h;
      }
    }
    long long int z = (k - 1) * 2 + (n - (k - 1) * 2) / 2;
    for (long long int i = (k - 1) * 2; i < z; i++) {
      if (s[i] == ')') {
        o = 0;
        c = 0;
        h = i;
        p[0].push_back(i);
        c++;
        i++;
        while (s[i] != '(' && i < n) {
          i++;
        }
        p[1].push_back(i);
        for (long long int g = 0; g < (i - h + 1) / 2; g++) {
          swap(s[i - g], s[h + g]);
        }
        i = h;
      }
    }
    for (long long int i = z; i < n; i++) {
      if (s[i] == '(') {
        o = 0;
        c = 0;
        h = i;
        p[0].push_back(i);
        o++;
        i++;
        while (s[i] != ')' && i < n) {
          i++;
        }
        p[1].push_back(i);
        for (long long int g = 0; g < (i - h + 1) / 2; g++) {
          swap(s[i - g], s[h + g]);
        }
        i = h;
      }
    }
    cout << p[0].size() << endl;
    for (long long int i = 0; i < p[0].size(); i++) {
      cout << p[0][i] + 1 << " " << p[1][i] + 1 << endl;
    }
  }
}
