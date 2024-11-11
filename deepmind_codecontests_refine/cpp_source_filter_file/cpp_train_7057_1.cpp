include <iostream>

using namespace std;

int main() {
  string s;
  int k;
  cin >> s >> k;
  int tmp = 1, buf = 0;
  long long ans = 0;
  for (int i = 1; i < s.size(); i++) {
    if (s[i-1] == s[i]) {
      tmp += 1;
    }
    else {
      if (!buf) buf = tmp;
      ans += tmp / 2;
      tmp = 1;
    }
  }
  if (!buf) {
    ans = tmp;
    ans = ans * k / 2;
    cout << ans << endl;
    return 0;
  }
  ans += tmp / 2;
  ans *= k;
  if (s.front() == s.back() && buf % 2 && tmp % 2) {
    ans += (k - 1);
  }
  cout << ans << endl;
}