#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<string> rs;
  if (n == 1) {
    rs.push_back("a");
    rs.push_back("a");
    rs.push_back("b");
    rs.push_back("b");
  } else if (n == 2) {
    rs.push_back("aa");
    rs.push_back("bb");
    rs.push_back("aa");
    rs.push_back("bb");
  } else if (n == 3) {
    rs.push_back("aac");
    rs.push_back("bbc");
    rs.push_back("add");
    rs.push_back("abb");
  } else if (n == 4) {
    rs.push_back("aabb");
    rs.push_back("cddc");
    rs.push_back("cddc");
    rs.push_back("aabb");
  } else if (n % 2 == 0) {
    int b = 0;
    int c = 5;
    int d = 10;
    string pal1 = "";
    string pal2 = "z";
    string pal3 = "z";
    for (int i = 0; i < n / 2; i++) {
      b = (b + 1) % 24;
      c = (c + 1) % 24;
      d = (d + 1) % 24;
      pal1 += string(2, char('a' + b));
      if (i == n / 2 - 1) continue;
      pal2 += string(2, char('a' + c));
      pal3 += string(2, char('a' + d));
    }
    pal2 += "z";
    pal3 += "z";
    rs.push_back(pal1);
    rs.push_back(pal2);
    rs.push_back(pal3);
    rs.push_back(pal1);
  } else if (n % 2 != 0) {
    int b = 0;
    int c = 5;
    int d = 10;
    string pal1 = "";
    string pal2 = "";
    string pal3 = "z";
    for (int i = 0; i < n / 2; i++) {
      b = (b + 1) % 24;
      c = (c + 1) % 24;
      d = (d + 1) % 24;
      pal1 += string(2, char('a' + b));
      pal2 += string(2, char('a' + c));
      pal3 += string(2, char('a' + d));
    }
    string pal4 = "z" + pal1;
    pal1 += "z";
    pal2 += "z";
    rs.push_back(pal1);
    rs.push_back(pal2);
    rs.push_back(pal3);
    rs.push_back(pal4);
  }
  for (int i = int(0); i < int(4); i++) {
    cout << rs[i] << "\n";
  }
  return 0;
}
