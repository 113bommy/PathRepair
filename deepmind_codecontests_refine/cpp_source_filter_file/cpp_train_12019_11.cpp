#include <bits/stdc++.h>
using namespace std;
const int N = 500000;
int n;
int aaa[N];
int main(void) {
  cin >> n;
  for (int i = 0; i < int(n); i++) {
    cin >> aaa[i];
  }
  vector<int> acc;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    acc.push_back(aaa[i]);
    int a = acc.size();
    while (a >= 3 && acc[a - 3] >= acc[a - 2] && acc[a - 2] <= acc[a - 1]) {
      sum += min(acc[a - 3], acc[a - 1]);
      acc.erase(acc.begin() + (a - 2));
      a--;
    }
  }
  sort(acc.begin(), acc.end());
  for (int i = 0; i < int(acc.size() - 2); i++) {
    sum += acc[i];
  }
  cout << sum << endl;
}
