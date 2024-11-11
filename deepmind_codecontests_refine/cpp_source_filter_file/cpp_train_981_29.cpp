#include <bits/stdc++.h>
using namespace std;
const long long INF = 20000000000000005ll;
const long long MOD = 1000000007;
int H, W, A[2005], K;
int main() {
  cin >> H >> W >> K;
  for (int i = (0); i <= (H - 1); i++) {
    string s;
    cin >> s;
    for (int j = (0); j <= (W - 1); j++)
      if (s[j] == 'U' && j % 2 == 0)
        A[j]++;
      else if (s[j] == 'L' && j - i >= 0)
        A[j - i]++;
      else if (s[j] == 'R' && j + i < W)
        A[j + i]++;
  }
  for (int i = (0); i <= (W - 1); i++) cout << A[i] << " ";
}
