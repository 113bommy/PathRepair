#include <bits/stdc++.h>
using namespace std;
string ex = "";
typedef struct {
  bool thr;
  int cat;
  string mes;
} block;
block p[1000000];
stack<int> k;
char temp[1000000];
int main() {
  int n;
  string rd;
  size_t found;
  size_t found2;
  size_t found3;
  size_t found4;
  bool ketemu = false;
  cin >> n;
  getchar();
  int bl = 0;
  for (int a = 1; a <= n; a++) {
    cin.getline(temp, 1000000);
    rd = temp;
    found = rd.find("try");
    found2 = rd.find("catch");
    found3 = rd.find("throw");
    found4 = rd.find(",");
    if ((found != string::npos) && (found2 == string::npos) &&
        (found3 == string::npos)) {
      bl++;
      k.push(bl);
      if (!ketemu)
        p[bl].thr = 1;
      else
        p[bl].thr = 0;
    } else {
      if ((found3 != string::npos) && (found4 == string::npos)) {
        ketemu = true;
        for (int a = (int)found + 5; a < rd.length(); a++) {
          if (((rd[a] >= 'A') && (rd[a] <= 'Z')) ||
              ((rd[a] >= 'a') && (rd[a] <= 'z')))
            ex += rd[a];
        }
      } else {
        if (found2 != string::npos) {
          string m, exx;
          for (int a = (int)found + 5; a < rd.length(); a++) {
            if (rd[a] == ',') {
              break;
            }
            if (((rd[a] >= 'A') && (rd[a] <= 'Z')) ||
                ((rd[a] >= 'a') && (rd[a] <= 'z')))
              exx += rd[a];
          }
          found = rd.find(",");
          bool bole = false;
          for (int a = (int)found; a < rd.length(); a++) {
            if (rd[a] == '"') {
              if (!bole)
                bole = true;
              else
                break;
            }
            if (bole) {
              if (((rd[a] >= 'A') && (rd[a] <= 'Z')) ||
                  ((rd[a] >= 'a') && (rd[a] <= 'z')) || rd[a] == ' ' ||
                  ((rd[a] >= '1') && (rd[a] <= '9')))
                m += rd[a];
            }
          }
          if (p[k.top()].thr) {
            if (exx == ex) {
              cout << m << endl;
              return 0;
            }
          }
          k.pop();
        }
      }
    }
  }
  cout << "Unhandled Exception" << endl;
  return 0;
}
