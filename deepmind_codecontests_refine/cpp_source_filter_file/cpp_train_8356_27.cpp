#include <bits/stdc++.h>
using namespace std;
void cs(string s) { cout << s << " "; }
void ci(long long int i) { cout << i << " "; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int T;
  cin >> T;
  while (T--) {
    long long int n;
    cin >> n;
    pair<long long int, pair<long long int, long long int> > p[14];
    bool a[14];
    memset(a, true, sizeof(a));
    a[1] = false;
    a[2] = false;
    a[4] = false;
    p[0] = {0, {0, 0}};
    p[3] = {1, {0, 0}};
    p[5] = {0, {1, 0}};
    p[6] = {2, {0, 0}};
    p[7] = {0, {0, 1}};
    p[8] = {1, {1, 0}};
    p[9] = {3, {0, 0}};
    p[10] = {0, {2, 0}};
    p[11] = {2, {1, 0}};
    p[12] = {4, {0, 0}};
    p[13] = {2, {0, 1}};
    long long int c = n / 7;
    n %= 7;
    if (c > 1 and n <= 4) {
      n += 7;
      c--;
    }
    if (a[n] == false)
      ci(-1);
    else {
      ci(p[n].first);
      ci(p[n].second.first);
      ci(p[n].second.second + c);
    }
    cout << "\n";
  }
}
