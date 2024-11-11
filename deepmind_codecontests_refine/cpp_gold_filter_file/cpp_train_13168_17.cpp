#include <bits/stdc++.h>
using namespace std;
map<int, int> buy, sell;
int v[105], c = 0;
int main() {
  int n, s;
  cin >> n >> s;
  char directie;
  int price, qq;
  while (n--) {
    cin >> directie;
    cin >> price >> qq;
    if (directie == 'B') {
      buy[-1 * price] += qq;
    } else {
      sell[price] += qq;
    }
  }
  int i = 0;
  for (map<int, int>::iterator it = sell.begin(); it != sell.end() && i < s;
       it++) {
    v[c + 2] = it->first;
    v[c + 1] = it->second;
    c += 2;
    i++;
  }
  for (int i = c; i > 1; i -= 2) {
    cout << "S " << v[i] << ' ' << v[i - 1] << '\n';
  }
  i = 0;
  for (map<int, int>::iterator it = buy.begin(); it != buy.end() && i < s;
       it++) {
    cout << "B " << -1 * it->first << ' ' << it->second << '\n';
    i++;
  }
  return 0;
}
