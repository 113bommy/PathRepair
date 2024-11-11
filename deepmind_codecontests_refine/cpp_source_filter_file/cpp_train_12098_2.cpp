#include <bits/stdc++.h>
using namespace std;
int main() {
  int amnt_of_requests;
  cin >> amnt_of_requests;
  vector<set<int>> rslt(amnt_of_requests);
  int n, sqrt_, tmp;
  for (int number_of_request = 0; number_of_request < amnt_of_requests;
       number_of_request++) {
    cin >> n;
    sqrt_ = int(sqrt(n));
    for (int i = sqrt_; i > 1; i--) {
      tmp = n / i;
      if (!rslt[number_of_request].count(tmp))
        rslt[number_of_request].insert(tmp);
    }
  }
  for (auto& it : rslt) {
    cout << *it.begin() + it.size() << '\n';
    for (int i = 0; i < *it.begin(); i++) cout << i << ' ';
    for (auto& i : it) {
      cout << i << ' ';
    }
    cout << '\n';
  }
  return 0;
}
