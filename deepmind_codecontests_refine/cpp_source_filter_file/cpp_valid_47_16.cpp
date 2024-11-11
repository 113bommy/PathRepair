#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k, num, count = 0, i, j;
  cin >> n >> k;
  bitset<32> b[6];
  for (i = 1; i < 3; i++) {
    for (j = i + 1; j <= 3; j++) {
      cout << "or " << i << " " << j << endl;
      cin >> num;
      b[count] = num;
      count++;
      cout << "and " << i << " " << j << endl;
      cin >> num;
      b[count] = num;
      count++;
    }
  }
  bitset<32> b1, b2;
  for (i = 0; i < 32; i++) {
    if (b[0][i] == b[1][i]) {
      b1[i] = b[0][i];
      b2[i] = b[0][i];
    } else {
      if (b[2][i] != b[4][i]) {
        b1[i] = b[2][i];
        b2[i] = b[4][i];
      } else {
        b1[i] = b[3][i];
        b2[i] = b[5][i];
      }
    }
  }
  bitset<32> r, ans;
  r = b1;
  vector<int> vec;
  vec.push_back(b1.to_ulong());
  vec.push_back(b2.to_ulong());
  b1 = b[2];
  b2 = b[3];
  for (i = 3; i <= n; i++) {
    if (i > 3) {
      cout << "or " << 1 << " " << j << endl;
      cin >> num;
      b1 = num;
      cout << "and " << 1 << " " << j << endl;
      cin >> num;
      b2 = num;
    }
    for (j = 0; j < 32; j++) {
      if (r[j] == 0 && b1[j] == 0)
        ans[j] = 0;
      else if (r[j] == 0 && b1[j] == 1)
        ans[j] = 1;
    }
    for (j = 0; j < 32; j++) {
      if (r[j] == 1 && b2[j] == 0)
        ans[j] = 0;
      else if (r[j] == 1 && b2[j] == 1)
        ans[j] = 1;
    }
    vec.push_back(ans.to_ulong());
  }
  sort(vec.begin(), vec.end());
  cout << "finish " << vec[k - 1] << endl;
  return 0;
}
