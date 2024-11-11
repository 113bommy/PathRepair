#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 10;
int t, n, k, dwk, rep[26], all;
string s;
vector<int> gr;
bool checked[mx];
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k >> s;
    for (int c = 0; c <= n / k; c++) {
      if (checked[c]) continue;
      gr.push_back(c);
      checked[c] = 1;
      for (int p = 0; p < gr.size(); p++)
        for (int i = gr[p]; i < n; i += k) {
          rep[s[i] - 97]++;
          all++;
          if (!checked[(n - i - 1) % k]) {
            gr.push_back((n - i - 1) % k);
            checked[(n - i - 1) % k] = 1;
          }
        }
      sort(rep, rep + 26);
      dwk += all - rep[25];
      memset(rep, 0, sizeof(rep));
      all = 0;
      gr.clear();
    }
    cout << dwk << endl;
    dwk = 0;
    memset(checked, 0, sizeof(checked));
  }
  return 0;
}
