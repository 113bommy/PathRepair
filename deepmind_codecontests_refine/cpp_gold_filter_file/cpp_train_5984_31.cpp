#include <bits/stdc++.h>
using namespace std;
long long cnt[36];
int main() {
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    if (isdigit(str[i])) {
      cnt[str[i] - '0' + 26]++;
    } else {
      cnt[str[i] - 'a']++;
    }
  }
  long long s(0);
  for (int i = 0; i < 36; i++) {
    s += cnt[i] * cnt[i];
  }
  cout << s << endl;
  return 0;
}
