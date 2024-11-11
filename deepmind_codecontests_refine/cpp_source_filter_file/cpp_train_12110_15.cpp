#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, marks[100][100], counter = 0, counter2 = 0;
  bool con[100];
  string c;
  cin >> a >> b;
  cin.ignore();
  fill(con, con + a, true);
  for (int i = 0; i < a; i++) {
    getline(cin, c);
    for (int j = 0; j < b; j++) marks[i][j] = c[j] - '0';
  }
  for (int stu = 0; stu < a; stu++) {
    for (int sub = 0; sub < b && con[stu]; sub++) {
      counter = 0;
      int maxi = marks[stu][sub];
      for (int rem = 0; rem < a && con[stu]; rem++)
        if (marks[rem][sub] >= maxi) counter++;
      if (counter == a) {
        counter2++;
        con[stu] = false;
      }
    }
  }
  cout << counter2 << endl;
}
