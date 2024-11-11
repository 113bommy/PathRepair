#include <bits/stdc++.h>
using namespace std;
int main() {
  string first, last;
  vector<string> moves;
  cin >> first >> last;
  int n = 0;
  while ((first[0] != last[0]) || (first[1] != last[1])) {
    n++;
    if ((first[0] == last[0]) && (first[1] < last[1])) {
      first[1]++;
      moves.push_back("U");
    } else if ((first[0] == last[0]) && (first[1] > last[1])) {
      first[1]--;
      moves.push_back("D");
    } else if ((first[0] < last[0]) && (first[1] == last[1])) {
      first[0]++;
      moves.push_back("R");
    } else if ((first[0] > last[0]) && (first[1] == last[1])) {
      first[0]--;
      moves.push_back("L");
    } else if ((first[0] < last[0]) && (first[1] < last[1])) {
      first[0]++;
      first[1]++;
      moves.push_back("RU");
    } else if ((first[0] < last[0]) && (first[1] > last[1])) {
      first[0]++;
      first[1]--;
      moves.push_back("RD");
    } else if ((first[0] > last[0]) && (first[1] < last[1])) {
      first[0]--;
      first[1]++;
      moves.push_back("LU");
    } else if ((first[0] > last[0]) && (first[1] > last[1])) {
      first[0]--;
      first[1]--;
      moves.push_back("LD");
    }
  }
  cout << n << endl;
  for (int i = 0; i < moves.size(); i++) cout << moves[i] << endl;
  return 0;
}
