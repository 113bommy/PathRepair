#include <bits/stdc++.h>
using namespace std;
int P[100010];
int Taken[100010];
int main() {
  int N;
  cin >> N;
  for (int i = 2; i <= N; i++) {
    if (P[i] == 0) {
      for (int j = i * 2; j <= N; j += i) P[j] = 1;
    }
  }
  std::vector<pair<int, int> > Ans;
  for (int i = N; i >= 2; i--) {
    if (P[i] == 0) {
      std::vector<int> Values;
      for (int j = i; j <= N; j += i) {
        if (Taken[j] == 0) Values.push_back(j);
      }
      if (Values.size() % 2 == 0) {
        for (int j = 0; j < Values.size(); j += 2) {
          Ans.push_back(make_pair(Values[j], Values[j + 1]));
          Taken[Values[j]] = 1;
          Taken[Values[j + 1]] = 1;
        }
      } else {
        for (int j = 0; j < Values.size(); j++) {
          if (Values[j] % 2 == 0) {
            swap(Values[j], Values.back());
            break;
          }
        }
        for (int j = 0; j < Values.size() - 1; j += 2) {
          Ans.push_back(make_pair(Values[j], Values[j + 1]));
          Taken[Values[j]] = 1;
          Taken[Values[j + 1]] = 1;
        }
      }
    }
  }
  cout << Ans.size() << endl;
  for (int i = 0; i < Ans.size(); i++)
    cout << Ans[i].first << " " << Ans[i].second << endl;
  return 0;
}
