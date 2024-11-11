#include <bits/stdc++.h>
using namespace std;
int getint(string s) {
  int x = stoi(s);
  return x;
}
string getstring(int x) {
  string lol = to_string(x);
  return lol;
}
int X[4] = {1, 0, -1, 0};
int Y[4] = {0, 1, 0, -1};
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
long long int expmod(long long int A, long long int B, long long int C) {
  if (A == 0) return 0;
  if (B == 0) return 1;
  long long int y;
  if (B % 2 == 0) {
    y = expmod(A, B / 2, C);
    y = (y * y) % C;
  } else {
    y = A % C;
    y = (y * expmod(A, B - 1, C) % C) % C;
  }
  return (long long int)((y + C) % C);
}
pair<int, int> comp(pair<int, int> a, pair<int, int> b) {
  if (a.second < b.first || a.first > b.second) return make_pair(-1, -1);
  return make_pair(max(a.first, b.first), min(a.second, b.second));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n;
  while (cin >> n) {
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      v.push_back(make_pair(x, y));
    }
    vector<pair<int, int> > pref, suf;
    pref.push_back(make_pair(0, 1e9 + 7));
    for (int i = 0; i < n; i++) {
      pref.push_back(comp(v[i], pref[i]));
    }
    suf.push_back(make_pair(0, 1e9 + 7));
    for (int i = n - 1, j = 0; i >= 0; i--, j++) {
      suf.push_back(comp(suf[j], v[i]));
    }
    reverse(suf.begin(), suf.end());
    int maxi = 0;
    for (int i = 0; i < n; i++) {
      pair<int, int> aux = comp(pref[i], suf[i + 1]);
      maxi = max(maxi, aux.second - aux.first);
    }
    cout << maxi << endl;
  }
}
