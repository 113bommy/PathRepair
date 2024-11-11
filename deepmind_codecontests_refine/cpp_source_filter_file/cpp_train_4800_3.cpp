#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  vector<long long int> ch;
  for (long long int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      ch.push_back(i);
    }
  }
  long long int count = 0, it = 0;
  while (ch.size() > 0 && it < ch.size() - 1) {
    if ((ch[it + 1] - ch[it] == 1) && (a[ch[it]] != a[ch[it + 1]])) {
      it += 2;
      count++;
    } else {
      it++;
      count += 2;
    }
  }
  if (it == ch.size() - 1) count++;
  cout << count << endl;
  return 0;
}
