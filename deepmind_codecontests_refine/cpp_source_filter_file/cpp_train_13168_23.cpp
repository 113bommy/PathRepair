#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
const int Mod = 1000000007;
const int Max = 100003;
int N, s;
pair<long long, long long> a[333333], b[333333];
pair<long long, long long> B[100];
pair<long long, long long> S[100];
map<long long, long long> ms;
map<long long, long long> mb;
int main() {
  cin >> N >> s;
  if (s == 0) {
    return 0;
  }
  char str;
  int k = 0, k2 = 0;
  for (int i = 0; i < N; i++) {
    cin >> str;
    if (str == 'B') {
      cin >> a[k2].first >> a[k2].second;
      k2++;
    } else {
      cin >> b[k].first >> b[k].second;
      k++;
    }
  }
  sort(a, a + k);
  sort(b, b + k2);
  for (int i = 0; i < k2; i++) mb[a[i].first] += a[i].second;
  for (int i = 0; i < k; i++) ms[b[i].first] += b[i].second;
  {
    int k = 0;
    for (int i = 0; i < Max && k < s; i++)
      if (ms[i] != 0) {
        S[k].first = i;
        S[k].second = ms[i];
        k++;
      }
    for (int i = k - 1; i >= 0; i--)
      cout << 'S' << ' ' << S[i].first << ' ' << S[i].second << endl;
    k = 0;
    for (int i = Max; i >= 0 && k < s; i--)
      if (mb[i] != 0) {
        cout << 'B' << ' ' << i << ' ' << mb[i] << endl;
        k++;
      }
  }
  return 0;
}
