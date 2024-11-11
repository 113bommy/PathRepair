#include <bits/stdc++.h>
using namespace std;
int main() {
  queue<unsigned long long> q;
  vector<unsigned long long> v;
  unsigned long long temp;
  q.push(0);
  while (!q.empty()) {
    temp = q.front();
    v.push_back(temp * 10 + 4);
    v.push_back(temp * 10 + 7);
    if (temp * 10 + 7 >= 4444444444) break;
    q.pop();
    q.push(temp * 10 + 4);
    q.push(temp * 10 + 7);
  }
  unsigned long long left, right, sum = 0;
  cin >> left >> right;
  int i = 0;
  for (i = 0; i < v.size(); i++)
    if (v[i] >= left) break;
  while (left < right) {
    sum = sum + v[i] * (min(v[i], right) - left + 1);
    left = v[i] + 1;
    i++;
  }
  cout << sum;
  return 0;
}
