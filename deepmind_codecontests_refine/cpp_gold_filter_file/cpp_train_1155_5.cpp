#include <bits/stdc++.h>
using namespace std;
int main() {
  int N = 0;
  while (cin >> N) {
    long long sum = 0;
    long long num = 0;
    vector<long long> res;
    for (int i = 0; i < N; i++) {
      cin >> num;
      if (i == 0)
        res.push_back(num);
      else
        res.push_back((num * (i + 1)) - i);
    }
    for (int k = 0; k < res.size(); k++) sum += res[k];
    cout << sum << endl;
  }
  return 0;
}
