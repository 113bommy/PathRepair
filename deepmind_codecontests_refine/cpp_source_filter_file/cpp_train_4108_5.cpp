#include <bits/stdc++.h>
using namespace std;
string taskname("");
void stdio() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
}
void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string input = taskname + ".in";
  string output = taskname + ".out";
  const char* inputfile = input.c_str();
  const char* outputfile = output.c_str();
  freopen(inputfile, "r", stdin);
  freopen(outputfile, "w", stdout);
}
int main() {
  stdio();
  int N;
  cin >> N;
  vector<int> D(N, 0);
  map<int, long long> value;
  long long dp[100005];
  for (int r = 0; r < N; r++) {
    int k;
    cin >> k;
    value[k] += k;
  }
  dp[0] = 0;
  dp[1] = value[1];
  dp[2] = value[2];
  dp[3] = value[3] + value[1];
  for (int r = 4; r < 100005; r++) {
    dp[r] = value[r] + max(dp[r - 2], dp[r - 3]);
  }
  cout << dp[100000] << endl;
}
