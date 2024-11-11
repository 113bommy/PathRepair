#include <bits/stdc++.h>
using namespace std;
int N;
string S;
vector<int> T;
bool f(int W) {
  int lines = 0;
  int s = 0;
  for (int x : T) {
    if (s + x > W) {
      lines++;
      s = 0;
    }
    s += x;
  }
  if (s > 0) lines++;
  return lines <= N;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  getline(cin, S);
  getline(cin, S);
  for (int i = 0; i < S.length(); i++) {
    if (S[i] == ' ') S[i] = '-';
  }
  int c = 0;
  for (int i = 0; i < S.length(); i++) {
    c++;
    if (S[i] == '-') {
      T.push_back(c);
      c = 0;
    }
  }
  T.push_back(c);
  int lo = *max_element((T).begin(), (T).end()) - 1, hi = 3000000;
  while (hi - lo > 1) {
    int mid = (lo + hi) / 2;
    if (f(mid))
      hi = mid;
    else
      lo = mid;
  }
  cout << hi << "\n";
  return 0;
}
