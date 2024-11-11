#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  int cnt[30] = {0};
  for (int i = 0; i < str.size(); i++) {
    int cnt1 = 0;
    for (int j = 0; j < str[i] - 'a'; j++) {
      if (cnt[j]) cnt1++;
    }
    cnt[str[i] - 'a']++;
    if (cnt1)
      cout << "Ann\n";
    else
      cout << "Mike\n";
  }
}
