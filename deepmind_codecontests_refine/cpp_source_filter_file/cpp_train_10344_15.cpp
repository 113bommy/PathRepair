#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  map<int, int> mp;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mp[x] = i;
  }
  int q;
  cin >> q;
  int vasya = 0, petya = 0;
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    vasya += mp[x] + 1;
    petya += n - mp[x];
  }
  cout << vasya << " " << petya;
}
