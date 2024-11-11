#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    vector<string> vect;
    string str;
    for (int i = (int)(1); i <= (int)(9); i++) {
      cin >> str;
      vect.push_back(str);
    }
    string s1;
    s1 = s1 + vect[0][0];
    long long val = stoi(s1);
    val = (val % 9) + 1;
    string s2 = to_string(val);
    char ch[2];
    ch[0] = s2[0];
    vect[0][0] = ch[0];
    s1.erase();
    s2.erase();
    s1 = s1 + vect[1][3];
    val = stoi(s1);
    val = (val % 9) + 1;
    s2 = to_string(val);
    ch[0] = s2[0];
    vect[1][3] = ch[0];
    s1.erase();
    s2.erase();
    s1 = s1 + vect[2][6];
    val = stoi(s1);
    val = (val % 9) + 1;
    s2 = to_string(val);
    ch[0] = s2[0];
    vect[2][6] = ch[0];
    s1.erase();
    s2.erase();
    s1 = s1 + vect[3][1];
    val = stoi(s1);
    val = (val % 9) + 1;
    s2 = to_string(val);
    ch[0] = s2[0];
    vect[3][1] = ch[0];
    s1.erase();
    s2.erase();
    s1 = s1 + vect[4][4];
    val = stoi(s1);
    val = (val % 9) + 1;
    s2 = to_string(val);
    ch[0] = s2[0];
    vect[4][4] = ch[0];
    s1.erase();
    s2.erase();
    s1 = s1 + vect[5][7];
    val = stoi(s1);
    val = (val % 9) + 1;
    s2 = to_string(val);
    ch[0] = s2[0];
    vect[5][7] = ch[0];
    s1.erase();
    s2.erase();
    s1 = s1 + vect[6][2];
    val = stoi(s1);
    val = (val % 9) + 1;
    s2 = to_string(val);
    ch[0] = s2[0];
    vect[6][2] = ch[0];
    s1.erase();
    s2.erase();
    s1 = s1 + vect[7][5];
    val = stoi(s1);
    val = (val % 9) + 1;
    s2 = to_string(val);
    ch[0] = s2[0];
    vect[7][5] = ch[0];
    s1.erase();
    s2.erase();
    s1 = s1 + vect[8][8];
    val = stoi(s1);
    val = (val % 9) + 1;
    s2 = to_string(val);
    ch[0] = s2[0];
    vect[8][8] = ch[0];
    for (int i = (int)(0); i <= (int)(8); i++) {
      cout << vect[i] << "\n";
    }
  }
}
