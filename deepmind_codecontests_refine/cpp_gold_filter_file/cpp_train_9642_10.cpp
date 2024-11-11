#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  int N;
  cin >> N;
  char s[101];
  scanf("%s", s);
  int ct1 = 0, ct2 = 0;
  for (int i = 1; i < N; i++) {
    if (s[i] == 'F' && s[i - 1] == 'S') ct1++;
    if (s[i] == 'S' && s[i - 1] == 'F') ct2++;
  }
  if (ct1 > (ct2)) {
    cout << "YES" << '\n';
  } else
    cout << "NO" << '\n';
}
