#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
long long gcd(long long a, long long b) {
  for (; b; a %= b, swap(a, b))
    ;
  return a;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string n;
    int k;
    cin >> n;
    cin >> k;
    while (true) {
      set<char> s;
      for (int i = 0; i < n.size(); i++) s.insert(n[i]);
      if (s.size() <= k) {
        cout << n << "\n";
        break;
      }
      s.clear();
      int ptr = 0;
      while (true) {
        s.insert(n[ptr]);
        if (s.size() > k) {
          while (n[ptr] == '9') ptr--;
          n[ptr]++;
          for (int i = ptr + 1; i < n.size(); i++) n[i] = 0;
          break;
        }
        ptr++;
      }
    }
  }
}
