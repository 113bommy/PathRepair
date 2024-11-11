#include <bits/stdc++.h>
using namespace std;
int Value[26];
long long Ar[100001];
map<long long, int> Mp[26];
int main() {
  for (int i = 0; i < 26; i++) scanf("%d", &Value[i]);
  string Input;
  cin >> Input;
  int n = Input.size();
  Input = "$" + Input;
  for (int i = 1; i <= n; i++) {
    Ar[i] += Ar[i - 1] + Value[Input[i] - 'a'];
  }
  long long res = 0;
  for (int i = n; i > 0; i--) {
    res += Mp[Input[i] - 'a'][Ar[i] + Value[Input[i] - 'a']];
    Mp[Input[i] - 'a'][Ar[i]]++;
  }
  cout << res << endl;
  return 0;
}
