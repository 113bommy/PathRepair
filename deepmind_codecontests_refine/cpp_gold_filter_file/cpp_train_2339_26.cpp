#include <bits/stdc++.h>
using namespace std;
const long long N = 5, INF = 1e9 + 7;
string s1, s2, s3;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> s1 >> s2 >> s3;
  if (s1 == "rock" && s2 == "scissors" && s3 == "scissors" ||
      s1 == "paper" && s2 == "rock" && s3 == "rock" ||
      s1 == "scissors" && s2 == "paper" && s3 == "paper")
    return cout << "F", 0;
  if (s2 == "rock" && s1 == "scissors" && s3 == "scissors" ||
      s2 == "paper" && s1 == "rock" && s3 == "rock" ||
      s2 == "scissors" && s1 == "paper" && s3 == "paper")
    return cout << "M", 0;
  if (s3 == "rock" && s2 == "scissors" && s1 == "scissors" ||
      s3 == "paper" && s2 == "rock" && s1 == "rock" ||
      s3 == "scissors" && s2 == "paper" && s1 == "paper")
    return cout << "S", 0;
  cout << "?";
}
