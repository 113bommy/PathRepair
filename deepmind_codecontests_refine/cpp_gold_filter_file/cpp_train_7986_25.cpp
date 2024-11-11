#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
bool isPrime(int x) {
  if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
  for (int i = 5; i * i <= x; i += 6)
    if (x % i == 0 || x % (i + 2) == 0) return 0;
  return 1;
}
inline void boostIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  boostIO();
  int a, n, m;
  cin >> a >> n >> m;
  vector<pair<int, int>> Rain(n);
  for (int i = 0; i < (n); ++i) {
    cin >> Rain[i].first;
    cin >> Rain[i].second;
  }
  vector<int> Umb(a + 1 + 10000);
  for (int i = 0; i < (m); ++i) {
    int x, y;
    cin >> x >> y;
    if (Umb[x] == 0)
      Umb[x] = y;
    else
      Umb[x] = min(Umb[x], y);
  }
  int index = 0;
  vector<pair<int, int>> AddRain;
  for (int i = 0; i < (a + 1); ++i) {
    if (i >= Rain[index].second) index++;
    if (index == m) break;
    if (Rain[index].first < i && Rain[index].second > i && Umb[i] != 0) {
      pair<int, int> temp1 = make_pair(Rain[index].first, i);
      pair<int, int> temp2 = make_pair(i, Rain[index].second);
      Rain[index] = temp2;
      AddRain.push_back(temp1);
    }
  }
  for (auto Pair : AddRain) {
    Rain.push_back(Pair);
  }
  sort(Rain.begin(), Rain.end());
  vector<int> DP(Rain.size());
  for (int i = 0; i < (DP.size()); ++i) {
    DP[i] = INT_MAX;
  }
  int ri = Rain.size();
  for (int j = a; j >= 0; --j) {
    if (ri != 0 && Rain[ri - 1].first >= j) ri--;
    if (Umb[j] != 0) {
      int Sum = 0;
      for (int i = ri; i < Rain.size(); ++i) {
        if (DP[i] != INT_MAX)
          Sum += DP[i];
        else
          Sum = INT_MAX;
        if (Umb[j] * (Rain[i].second - j) < Sum) {
          DP[i] = Umb[j] * (Rain[i].second - j);
          for (int k = i - 1; k >= ri; --k) {
            DP[k] = 0;
          }
          Sum = DP[i];
        }
      }
    }
  }
  int Answ = 0;
  for (auto v : DP) {
    if (v == INT_MAX) {
      cout << -1 << endl;
      return 0;
    } else
      Answ += v;
  }
  cout << Answ;
  return 0;
}
