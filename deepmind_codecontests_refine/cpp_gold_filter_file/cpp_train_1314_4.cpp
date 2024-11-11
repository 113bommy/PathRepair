#include <bits/stdc++.h>
using namespace std;
struct fuck {
  int a;
  int x;
};
fuck a[500000];
int n;
void get_it(int &x) {
  for (int i = 0; i < n; ++i) {
    if (a[i].a == 0) x |= a[i].x;
    if (a[i].a == 1) x &= a[i].x;
    if (a[i].a == 2) x ^= a[i].x;
  }
}
int main() {
  string str;
  cin >> n;
  int x;
  for (int i = 0; i < n; ++i) {
    cin >> str >> x;
    if (str == "|") {
      a[i].a = 0;
    }
    if (str == "&") {
      a[i].a = 1;
    }
    if (str == "^") {
      a[i].a = 2;
    }
    a[i].x = x;
  }
  int zero = 0;
  int one = 0;
  for (int i = 0; i < 10; ++i) one += (1 << i);
  int ans2 = one;
  get_it(zero);
  get_it(one);
  int ans1 = 0, ans3 = 0;
  for (int i = 0; i < 10; ++i) {
    if (((1 << i) & one) == 0 && ((1 << i) & zero) == 0) {
      ans2 ^= (1 << i);
    }
    if (((1 << i) & one) != 0 && ((1 << i) & zero) == 0) {
    }
    if (((1 << i) & one) == 0 && ((1 << i) & zero) != 0) {
      ans3 |= (1 << i);
    }
    if (((1 << i) & one) != 0 && ((1 << i) & zero) != 0) {
      ans1 |= (1 << i);
    }
  }
  cout << 3 << endl;
  cout << "| " << ans1 << endl;
  cout << "& " << ans2 << endl;
  cout << "^ " << ans3 << endl;
  return 0;
}
