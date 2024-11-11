#include <bits/stdc++.h>
using namespace std;
vector<long long> card(40005);
void fun() {
  card[0] = 0;
  for (int i = 1; i < 40005; i++) {
    long long s1 = i * (i + 1);
    long long s2 = (i * (i - 1)) / 2;
    card[i] = (s1 + s2);
  }
}
int main() {
  fun();
  int t;
  cin >> t;
  while (t--) {
    long long n, ans = 0;
    cin >> n;
    while (true) {
      auto temp = lower_bound(card.begin(), card.end(), n) - card.begin();
      if (card[temp] > n) temp--;
      if (temp == 0 || n == 0) break;
      n -= card[temp];
      ans++;
    }
    cout << ans << "\n";
  }
}
