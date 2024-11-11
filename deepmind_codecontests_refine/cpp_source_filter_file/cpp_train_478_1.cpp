#include <bits/stdc++.h>
using namespace std;
struct node {
  int amp, str, flag;
};
node in[1000];
map<string, int> mp;
int main() {
  int n, ct = 0;
  in[0].flag = 1;
  ct = 1;
  mp["void"] = ct++;
  in[mp["void"]].flag = 1;
  in[mp["void"]].amp = in[mp["void"]].str = 0;
  cin >> n;
  while (n--) {
    string a, b, c;
    cin >> a;
    cin >> b;
    if (a == "typedef") {
      node &temp = in[ct++];
      temp.flag = 1;
      temp.amp = temp.str = 0;
      string x = "";
      for (int i = 0; i < b.size(); i++) {
        if (b[i] == '&')
          temp.amp++;
        else if (b[i] == '*')
          temp.str++;
        else
          x += b[i];
      }
      if (in[mp[x]].flag == 0)
        temp.flag = 0;
      else {
        temp.str += in[mp[x]].str;
        temp.amp += in[mp[x]].amp;
        temp.str -= temp.amp;
        temp.amp = 0;
        temp.flag = (temp.str >= 0);
      }
      cin >> c;
      mp[c] = ct - 1;
    } else {
      string x = "";
      node temp;
      temp.amp = 0;
      temp.str = 0;
      temp.flag = 1;
      for (int i = 0; i < b.size(); i++) {
        if (b[i] == '&')
          temp.amp++;
        else if (b[i] == '*')
          temp.str++;
        else
          x += b[i];
      }
      if (in[mp[x]].flag == 0)
        cout << "errtype"
             << "\n";
      else {
        temp.str += in[mp[x]].str;
        temp.amp += in[mp[x]].amp;
        temp.str -= temp.amp;
        temp.amp = 0;
        temp.flag = (temp.str >= 0);
        if (temp.flag == 0) {
          cout << "errtype"
               << "\n";
          continue;
        }
        cout << "void";
        for (int i = 0; i < temp.str; i++) cout << "*";
        cout << "\n";
      }
    }
  }
  return 0;
}
