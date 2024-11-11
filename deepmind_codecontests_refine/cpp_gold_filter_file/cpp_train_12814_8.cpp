#include <bits/stdc++.h>
using namespace std;
int N, B[30];
vector<int> ans;
string a, b;
char aux;
int main() {
  cin >> N;
  cin >> a >> b;
  for (int i = 0; i < N; i++) B[a[i] - 'a']++, B[b[i] - 'a']--;
  for (int i = 0; i < 26; i++) {
    if (B[i] != 0) {
      cout << "-1\n";
      return 0;
    }
  }
  for (int i = N - 1; i > 0; i--) {
    for (int j = i; j >= 0; j--) {
      if (a[j] == b[i]) {
        for (int k = j; k < i; k++) {
          aux = a[k + 1];
          a[k + 1] = a[k];
          a[k] = aux;
          ans.push_back(k + 1);
        }
        break;
      }
    }
  }
  cout << ans.size() << "\n";
  for (auto i : ans) cout << i << " ";
  cout << "\n";
  return 0;
}
