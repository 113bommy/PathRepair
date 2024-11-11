#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, cnt = 0;
  string str;
  cin >> k >> str;
  if (k == 0) {
    long long sum1 = 0;
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == '0')
        cnt++;
      else {
        sum1 += (cnt * (cnt + 1)) / 2;
        cnt = 0;
      }
    }
    sum1 += (cnt * (cnt + 1)) / 2;
    cout << sum1;
    return 0;
  }
  if (k == 1 && str.size() == 1) {
    if (str[0] == '1')
      cout << 1;
    else
      cout << 0;
    return 0;
  }
  if (str.size() == 1) {
    if (k > str.size()) {
      cout << 0;
      return 0;
    }
  }
  long long n = str.size();
  vector<long long> v;
  vector<long long> pre, post;
  int c = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '1') {
      v.push_back(i);
      pre.push_back(cnt);
      if (c != 0) post.push_back(cnt);
      cnt = 0;
      c++;
    } else
      cnt++;
  }
  if (v.size() < k) {
    cout << 0;
    return 0;
  }
  post.push_back((n - 1) - v[v.size() - 1]);
  long long i = 0, j = k - 1;
  if (str.size() < k) {
    cout << 0;
    return 0;
  }
  long long sum = 0;
  while (1) {
    sum += pre[i] + post[j] + min(pre[i], post[j]) + 1;
    i++;
    j++;
    if (j == v.size()) break;
  }
  cout << sum;
}
