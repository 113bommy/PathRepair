#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, n, low, high;
  cin >> a >> b;
  long long mini = min(a, b);
  vector<long long> v;
  vector<long long>::iterator itr1, itr2;
  for (int i = 1; i * i <= mini; i++) {
    if (mini % i == 0) {
      v.push_back(i);
      if (mini / i != i) v.push_back(mini / i);
    }
  }
  sort(v.begin(), v.end());
  cin >> n;
  while (n--) {
    cin >> low >> high;
    itr1 = lower_bound(v.begin(), v.end(), low);
    long long strt = itr1 - v.begin();
    strt--;
    if (v[strt] != low) strt++;
    itr2 = lower_bound(v.begin(), v.end(), high + 1);
    long long ends = itr2 - v.begin();
    ends--;
    if (strt > ends)
      cout << "-1" << endl;
    else {
      int flag = 1;
      for (int i = ends; i >= strt; i--) {
        if (a % v[i] == 0 && b % v[i] == 0) {
          flag = 0;
          cout << v[i] << endl;
          break;
        }
      }
      if (flag == 1) cout << "-1" << endl;
    }
  }
  return 0;
}
