#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p;
  cin >> n >> p;
  string str;
  long long apple = 0;
  int count = 0;
  vector<string> list;
  for (int i = 0; i < n; ++i) {
    cin >> str;
    list.push_back(str);
  }
  while (!list.empty()) {
    str = list.back();
    if (str == "halfplus") {
      apple = apple * 2 + 1;
      count++;
    } else
      apple = apple * 2;
    list.pop_back();
  }
  cout << p * apple - p / 2 * count << endl;
}
