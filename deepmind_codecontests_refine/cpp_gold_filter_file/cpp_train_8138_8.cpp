#include <bits/stdc++.h>
using namespace std;
void swap(int& x, int& y) {
  if (x > y) {
    int temp = x;
    x = y;
    y = temp;
  }
  return;
}
int main(int argc, const char* argv[]) {
  int n, k;
  cin >> n >> k;
  vector<int> x;
  for (int i = 0; i < k; i++) {
    x.push_back(i);
    cin >> x[i];
  }
  vector<long long> answer(n + 2);
  for (int i = 0; i < k - 1; i++) {
    int l = x[i + 1], m = x[i];
    swap(l, m);
    if (l == m) {
    } else {
      answer[l] += (m - 1);
      answer[l + 1] -= (m - 1);
      answer[m] += (l);
      answer[m + 1] -= l;
      answer[m + 1] += (m - l);
      answer[0] += (m - l);
      answer[l] -= (m - l);
      answer[l + 1] += (m - l - 1);
      answer[m] -= (m - l - 1);
    }
  }
  for (int i = 1; i < n + 2; i++) {
    answer[i] += answer[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    cout << answer[i] << " ";
  }
  cout << endl;
  return 0;
}
