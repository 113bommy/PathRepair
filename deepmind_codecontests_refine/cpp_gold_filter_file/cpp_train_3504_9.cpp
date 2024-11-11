#include <bits/stdc++.h>
using namespace std;
int n;
priority_queue<long long> v[64];
int findSize(long long a) {
  int ret = 0;
  while (a != 0) {
    a /= 2;
    ret++;
  }
  return ret;
}
int first0(long long a) {
  int size = findSize(a);
  for (int i = size - 1; i >= 0; i--) {
    if ((((long long)1 << i) & a) == 0) return i + 1;
  }
  return 0;
}
vector<long long> res;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long imsi;
    cin >> imsi;
    v[findSize(imsi)].push(imsi);
  }
  long long sum;
  for (int i = 0; i < 64; i++) {
    if (!v[i].empty()) {
      sum = v[i].top();
      v[i].pop();
      res.push_back(sum);
      break;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    int size = findSize(sum);
    int first = first0(sum);
    int k;
    for (k = 0; k < size; k++) {
      if ((((long long int)1 << k) & sum) == 0) {
        if (!v[k + 1].empty()) {
          sum ^= v[k + 1].top();
          res.push_back(v[k + 1].top());
          v[k + 1].pop();
          break;
        }
      }
    }
    if (k != size) continue;
    int j;
    for (j = size + 1; j < 64; j++) {
      if (!v[j].empty()) {
        sum ^= v[j].top();
        res.push_back(v[j].top());
        v[j].pop();
        break;
      }
    }
    if (j == 64) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << ' ';
  }
}
