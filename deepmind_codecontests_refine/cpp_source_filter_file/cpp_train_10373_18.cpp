#include <bits/stdc++.h>
using namespace ::std;
int MAXM = 1005;
const int P = 1e9 + 7;
vector<vector<int> > choose(MAXM, vector<int>(MAXM, 0));
int N, M;
int main() {
  ios::sync_with_stdio(false);
  ifstream fin("input.txt");
  choose[0][0] = 1;
  for (int i = 0; i < MAXM - 1; i++) {
    for (int j = 0; j < MAXM - 1; j++) {
      choose[i + 1][j] = (choose[i + 1][j] + choose[i][j]) % P;
      choose[i + 1][j + 1] = (choose[i + 1][j + 1] + choose[i][j]) % P;
    }
  }
  vector<long long> func(MAXM);
  func[0] = 1;
  func[1] = 1;
  for (int i = 2; i < MAXM; i++) {
    for (int j = 0; j <= i - 1; j++) {
      func[i] = (func[i] + choose[i - 1][j] * func[i - j - 1]);
    }
  }
  cin >> M >> N;
  vector<int> groups(M, 0);
  int cnt = 1;
  for (int i = 0; i < N; i++) {
    map<int, int> conv;
    string str;
    cin >> str;
    for (int j = 0; j < M; j++) {
      if (str[j] == '1') {
        if (conv.count(groups[j]) == 0) {
          conv[groups[j]] = cnt;
          cnt++;
        }
        groups[j] = conv[groups[j]];
      }
    }
  }
  map<int, int> group_cnt;
  for (int i = 0; i < M; i++) {
    group_cnt[groups[i]]++;
  }
  long long answ = 1;
  for (auto i : group_cnt) {
    answ = (answ * func[i.second]) % P;
  }
  cout << answ << "\n";
}
