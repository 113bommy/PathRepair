#include <bits/stdc++.h>
using namespace std;
string temp, str;
int test;
vector<pair<int, pair<int, int>>> answer;
void decode() {
  if (cin >> temp) {
    str += temp;
    if (temp == "pair") {
      str += "<", decode(), str += ", ", decode(), str += ">";
    }
  } else
    test = 1;
}
int main() {
  cin >> temp;
  decode();
  if (test || cin >> str)
    cout << "Error occured" << endl;
  else
    cout << str << endl;
}
