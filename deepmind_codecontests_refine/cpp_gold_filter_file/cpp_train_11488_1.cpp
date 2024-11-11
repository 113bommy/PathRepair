#include <bits/stdc++.h>
using namespace std;
struct Product {
  int buy_price;
  int sell_price;
  int count;
  Product(int a = 0, int b = 0, int c = 0)
      : buy_price(a), sell_price(b), count(c) {}
};
inline int min(int a, int c) { return a < c ? a : c; }
inline int max(int a, int c) { return a > c ? a : c; }
int main(int argc, char **argv) {
  int n;
  cin >> n;
  int m;
  cin >> m;
  int k;
  cin >> k;
  vector<vector<Product> > p(n);
  for (int planet = 0; planet < n; planet++) {
    string name;
    cin >> name;
    vector<Product> pr(m);
    for (int product = 0; product < m; product++) {
      int a, b, c;
      cin >> a;
      cin >> b;
      cin >> c;
      pr[product] = Product(a, b, c);
    }
    p[planet] = pr;
  }
  int result = 0;
  for (int buy_planet = 0; buy_planet < n; ++buy_planet) {
    for (int sell_planet = 0; sell_planet < n; ++sell_planet) {
      if (buy_planet == sell_planet) continue;
      vector<Product> p_buy = p[buy_planet];
      vector<Product> p_sell = p[sell_planet];
      int capacity = k;
      int profit = 0;
      while (capacity > 0) {
        int best_index = 0;
        int best_diff = -1;
        for (int i = 0; i < m; i++) {
          int diff = (p_sell[i].sell_price - p_buy[i].buy_price);
          if (p_buy[i].count > 0 && diff > best_diff) {
            best_index = i;
            best_diff = diff;
          }
        }
        if (best_diff == -1) break;
        int trade_count = min(p_buy[best_index].count, capacity);
        capacity -= trade_count;
        profit += best_diff * trade_count;
        p_buy[best_index].count -= trade_count;
      }
      result = max(result, profit);
    }
  }
  cout << result;
  return 0;
}
