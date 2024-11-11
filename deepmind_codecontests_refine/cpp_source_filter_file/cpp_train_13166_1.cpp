#include <bits/stdc++.h>
using namespace std;
long long val[27];
long long accS[100005];
map<int, long long> lett[27];
int main(int argc, char const* argv[]) {
  for (int i = 0; i < 26; i += 1) {
    cin >> val[i];
  }
  char str[100005];
  scanf("%s", str);
  int len = strlen(str);
  long long total = 0;
  for (int i = 1; i <= len; i += 1) {
    int idx = str[i - 1] - 'a';
    accS[i] = accS[i - 1] + val[idx];
    long long reqV = accS[i - 1];
    total += lett[idx][reqV];
    ++lett[idx][accS[i]];
  }
  cout << total << "\n";
  return 0;
}
