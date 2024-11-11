#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1001001001;

int main() {
  int N, H;
  cin >> H >> N;
  vector<int> dp(H + 1, MAX);
  dp[0] = 0;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    for (int j = 0; j < H; j++) {
      int index = min(j + a, H);
      dp[index] = min(dp[index], dp[j] + b); 
    }
  }
  cout << dp[H] << endl;
}
