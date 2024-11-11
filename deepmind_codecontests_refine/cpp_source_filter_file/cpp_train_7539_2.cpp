#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string a, b;
  cin >> a >> b;
  map<char, int> ma, mb;
  for (int i = 0; i < a.size(); i++) {
    ma[a[i]]++;
  }
  for (int i = 0; i < b.size(); i++) {
    if (ma[b[i]] == 0) {
      return cout << -1 << endl, 0;
    }
    mb[b[i]]++;
  }
  int total = 0;
  for (char i = 'a'; i < 'z'; i++) {
    total += min(ma[i], mb[i]);
  }
  cout << total << endl;
  return 0;
}
