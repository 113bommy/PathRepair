#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, L;
  cin >> N >> L;
  char s[110];
  for (int i = 0; i < N; i++) cin >> s[i];
  sort(s, s + N);
  for (int i = 0; i < N; i++) cout << s[i];
  cout << endl;
}
