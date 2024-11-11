#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  int cnt[26] = {0};
  for (int i = 0; i < h * w; ++i) {
    char c;
    cin >> c;
    cnt[c % 26]++;
  }

  int a = 0, b = 0;
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] & 1) {
      a++;
      cnt[i]--;
    }
    if (cnt[i] % 4) {
      b++;
    }
  }

  int c = (h & 1) && (w & 1);
  int d = (w & 1) * (h / 2) + (h & 1) * (w / 2);

  cout << (a == c && b <= d ? "Yes" : "No") << endl;
}
