#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ;
  long long int help[] = {1, 6, 8, 9};
  map<long long int, string> remToNum;
  while (remToNum.size() < 7) {
    long long int rem =
        help[0] * 1000LL + help[1] * 100LL + help[2] * 10LL + help[3];
    rem = rem % 7;
    if (remToNum.find(rem) == remToNum.end()) {
      for (long long int i = 0; i < 4; i++) {
        remToNum[rem] = remToNum[rem] + ((char)(help[i] + '0'));
      }
    }
    if (next_permutation(help, help + 4) == false) break;
  }
  string inp, ans;
  long long int zeros = 0;
  cin >> inp;
  bool a1, a6, a8, a9;
  a1 = a6 = a8 = a9 = false;
  long long int reminp = 0LL;
  for (long long int i = 0; i < inp.size(); i++) {
    if (inp[i] == '1' && a1 == false) {
      a1 = true;
      continue;
    }
    if (inp[i] == '6' && a6 == false) {
      a6 = true;
      continue;
    }
    if (inp[i] == '8' && a8 == false) {
      a8 = true;
      continue;
    }
    if (inp[i] == '9' && a9 == false) {
      a9 = true;
      continue;
    }
    if (inp[i] == '0') {
      zeros++;
      continue;
    }
    cout << inp[i];
    reminp = (reminp * 10 + (inp[i] - '0'));
    reminp = reminp % 7LL;
  }
  reminp = (reminp * 10000) % 7;
  cout << remToNum[(7 - reminp) % 7];
  for (long long int i = 0; i < zeros; i++) cout << 0 << endl;
  return 0;
}
