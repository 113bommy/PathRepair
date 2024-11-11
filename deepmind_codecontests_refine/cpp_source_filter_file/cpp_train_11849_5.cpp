#include <iostream>
using namespace std;

int f[26];
#define MOD 1000000007

int main() {
  int n;
  String s;
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) {
     f[s[i]-'a']++;
  }
  long long ans = 1;
  for (int i = 0; i < 26; i++) {
    ans = (ans*(f[i]+1))%MOD;
  }
  cout << ans << endl;
}