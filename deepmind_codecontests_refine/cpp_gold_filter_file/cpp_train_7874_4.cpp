#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O2")
#pragma GCC optimization("unroll-loops")
const long double ERR = 1e-5;
const int MOD = 1e9 + 7;
bool areEqual(long double _n1, long double _n2) {
  return fabs(_n1 - _n2) < ERR;
}
set<string> normalResponses, grumpyResponses;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  normalResponses.insert("great");
  normalResponses.insert("don't think so");
  normalResponses.insert("don't touch me");
  normalResponses.insert("not bad");
  normalResponses.insert("cool");
  grumpyResponses.insert("don't even");
  grumpyResponses.insert("are you serious");
  grumpyResponses.insert("no way");
  grumpyResponses.insert("go die in a hole");
  grumpyResponses.insert("worse");
  grumpyResponses.insert("terrible");
  for (int i = 0; i < 10; i++) {
    cout << i << '\n';
    cout.flush();
    string response;
    getline(cin, response);
    if (response == "no") continue;
    if (normalResponses.find(response) != normalResponses.end())
      cout << "normal" << '\n';
    else if (grumpyResponses.find(response) != grumpyResponses.end())
      cout << "grumpy" << '\n';
    else
      cout << response << '\n';
    cout.flush();
    break;
  }
}
