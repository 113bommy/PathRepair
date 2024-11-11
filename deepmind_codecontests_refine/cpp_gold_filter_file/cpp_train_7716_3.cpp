#include <bits/stdc++.h>
using namespace std;
long long int a[200000];
int main() {
  long long int n, k;
  cin >> n >> k;
  priority_queue<int> a;
  for (int i = 0; i < 31; i++) {
    if ((n >> i) & 1) a.push(pow(2, i));
  }
  if (a.size() > k || n < k) {
    cout << "NO";
    return 0;
  }
  while (a.size() < k) {
    int temp = a.top();
    a.pop();
    a.push(temp / 2);
    a.push(temp / 2);
  }
  cout << "YES" << endl;
  while (a.size() != 0) {
    cout << a.top() << " ";
    a.pop();
  }
  return 0;
}
