#include <bits/stdc++.h>
using namespace std;
int dr[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dc[] = {0, 1, 0, -1, 1, 1, -1, -1};
using namespace std;
long long q, n, k;
int cnt[26 + 7];
int main() {
  cin >> q;
  while (q--) {
    memset(cnt, 0, sizeof(cnt));
    string tmp;
    cin >> tmp;
    for (int i = 0; i < tmp.length(); i++) {
      cnt[tmp[i] - 97]++;
    }
    if (1) {
      for (int i = 0; i < 26; i++) cout << cnt[i] << " ";
      cout << endl;
    }
    long long single = 0, more = 0;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] == 1)
        single++;
      else if (cnt[i] > 1)
        more++;
    }
    single = floor(single / 2);
    cout << single + more << endl;
  }
}
