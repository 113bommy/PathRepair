#include <bits/stdc++.h>
using namespace std;
string AI_name, phone_name;
int main() {
  int ans = 0;
  cin >> AI_name >> phone_name;
  int len_AI = AI_name.length();
  int len_phone = phone_name.length();
  for (int i = 0; i <= len_AI - len_phone; i++) {
    if (AI_name.substr(i, len_phone) == phone_name) {
      AI_name[i + len_phone - 1] = '#';
      ans += 1;
    }
  }
  cout << ans << endl;
  return 0;
}
