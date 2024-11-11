#include <bits/stdc++.h>
using namespace std;
long long S, K;
vector<long long> fib;
int main(int argc, char *argv[]) {
  cin >> S >> K;
  fib.push_back(1);
  fib.push_back(1);
  for (int i = 2;; ++i) {
    long long tmp = 0;
    for (int j = i - 1; j >= i - K && j >= 0; --j) {
      tmp += fib[j];
    }
    if (tmp >= S) break;
    fib.push_back(tmp);
  }
  vector<long long> ans;
  for (int i = ((int)((fib).size())) - 1; i >= 1; --i) {
    if (fib[i] <= S) {
      S -= fib[i];
      ans.push_back(fib[i]);
    }
  }
  if (((int)((ans).size())) == 1) {
    ans.push_back(0);
  }
  cout << ((int)((ans).size())) << endl;
  for (int i = 0; i < ((int)((ans).size())); ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
