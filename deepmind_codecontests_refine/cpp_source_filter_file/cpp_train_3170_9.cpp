#include <bits/stdc++.h>
using namespace std;
int main() {
  int len;
  cin >> len;
  string input;
  vector<string> inputS;
  bool first = false;
  string firstTeam;
  ;
  string secondTeam;
  for (int j = 0; j < len; j++) {
    cin >> input;
    if (count(inputS.begin(), inputS.end(), input) == 0 && first == false) {
      firstTeam = input;
      first = true;
    } else if (count(inputS.begin(), inputS.end(), input) == 0 &&
               first == true) {
      secondTeam = input;
    }
    inputS.push_back(input);
  }
  int firstScore = count(inputS.begin(), inputS.end(), firstTeam);
  int secondScore = count(inputS.begin(), inputS.end(), secondTeam);
  if (firstScore > secondScore) {
    cout << firstTeam << endl;
  } else if (secondScore > firstScore) {
    cout << secondScore << endl;
  }
  return 0;
}
