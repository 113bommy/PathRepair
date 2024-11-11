#include <bits/stdc++.h>
using namespace std;
int x;
int a, b, c;
vector<int> ans;
map<long long, int> h;
int check(int x) {
  int sum = 0;
  while (x) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}
int second(int a, int b) {
  long long sum = 1ll;
  for (int i = 1; i <= b; i++) {
    sum *= a;
  }
  return sum;
}
int main() {
  cin >> a >> b >> c;
  for (int i = 0; i <= 100; i++) {
    long long res = b * second(i, a) + c;
    if (!h[res]) {
      h[res] = 1;
      if (res > 0 && res < 1000000000 && check(res) == i) {
        ans.push_back(res);
      }
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << ' ';
  }
  return 0;
}
