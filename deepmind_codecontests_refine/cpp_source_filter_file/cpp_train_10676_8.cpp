#include <bits/stdc++.h>
using namespace std;
int dx8[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy8[8] = {0, 0, 1, -1, 1, -1, 1, -1};
void file() {}
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long memo[100][(1 << 15)];
vector<vector<long long>> v(20);
int n;
long long best(int i, bitset<20> mask) {
  if (i == n) return 0;
  long long &ret = memo[i][mask.to_ulong()];
  if (ret != -1) return ret;
  long long maskcpy = mask.to_ulong();
  ret = 0;
  for (long long submaskcpy = maskcpy;;
       submaskcpy = (submaskcpy - 1) & (maskcpy)) {
    bitset<20> submask = submaskcpy;
    bool ok = 1;
    long long sum = 0;
    for (int j = 0; j < n; j++) {
    }
    if (ok) ret = max(ret, sum + best(i + 1, submask));
    if (!submaskcpy) break;
  }
  return ret;
}
vector<vector<bitset<20>>> masks(1 << 15);
void makemasks() {
  for (int i = 0; i < (1 << 15); i++) {
    bitset<20> mask = i;
    mask.flip();
    long long maskcpy = mask.to_ulong();
    mask.flip();
    for (long long submaskcpy = maskcpy;;
         submaskcpy = (submaskcpy - 1) & (maskcpy)) {
      bitset<20> submask = submaskcpy;
      bool ok = 1;
      for (int j = 0; j < n; j++) {
        if (submask[j]) {
          if (((j + 1 < n && submask[j + 1])) || (j - 1 >= 0 && mask[j - 1]) ||
              (j + 1 < n && mask[j + 1])) {
            ok = 0;
            break;
          }
        }
      }
      if (ok) {
        masks[i].push_back(submask);
      }
      if (!submaskcpy) break;
    }
  }
}
int main() {
  file();
  fast();
  long long n;
  cin >> n;
  cout << 2 << endl;
  for (int i = 2; i <= n; i++) {
    cout << i * (i + 1) * (i + 1) - i + 1 << endl;
  }
}
