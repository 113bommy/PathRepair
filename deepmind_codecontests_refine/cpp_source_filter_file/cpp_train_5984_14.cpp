#include <bits/stdc++.h>
using namespace std;
long long n;
string s;
char A[100005];
map<char, int> sample;
int main() {
  cin >> s;
  int pos = 0;
  for (int i = 0; i < s.length(); i++) {
    if (sample[s[i]] == 0) {
      A[pos] = s[i];
      pos++;
    }
    sample[s[i]]++;
  }
  for (int i = 0; i < pos; i++) {
    n += sample[A[i]] * sample[A[i]];
  }
  cout << n << endl;
  return 0;
}
