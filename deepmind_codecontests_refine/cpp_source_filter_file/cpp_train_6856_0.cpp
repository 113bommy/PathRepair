#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
int main() {
  int N;
  cin >> N;
  long long tot = 0;
  int index;
  for (int i = 1; i < N; i++) {
    tot += i;
    index = i;
    if (tot >= N) break;
  }
  int Exclusion = tot - N;
  for (int i = 1; i <= index; i++) {
    if (i != Exclusion) cout << i << endl;
  }
}
