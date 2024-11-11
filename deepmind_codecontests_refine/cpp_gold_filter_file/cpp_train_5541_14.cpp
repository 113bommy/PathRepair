#include <bits/stdc++.h>
using namespace std;
int main() {
  string temp;
  int n, m, mi = 0, ma = 0, itemp;
  vector<string> vec;
  vector<int> num;
  vector<int> price;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> itemp;
    price.push_back(itemp);
  }
  sort(price.begin(), price.end());
  int check = 0;
  for (int i = 0; i < m; i++) {
    cin >> temp;
    for (int i = 0; i < vec.size(); i++) {
      if (vec[i] == temp) {
        num[i]++;
        check++;
        break;
      }
    }
    if (check == 0) {
      vec.push_back(temp);
      num.push_back(1);
    }
    check = 0;
  }
  sort(num.begin(), num.end());
  for (int i = 0; i < num.size(); i++)
    mi += (num[num.size() - i - 1] * price[i]);
  for (int i = 0; i < num.size(); i++)
    ma += (num[num.size() - i - 1] * price[price.size() - i - 1]);
  cout << mi << " " << ma;
  return 0;
}
