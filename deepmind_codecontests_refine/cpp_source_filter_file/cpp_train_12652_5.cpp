#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int dir_r[] = {1, 0, -1, 0, -1, 1, -1, 1};
int dir_c[] = {0, 1, 0, -1, -1, 1, 1, -1};
int main(void) {
  int a, ta, b, cnt = 0, tb, n1, n2, a_departion, a_arrival, b_arrival,
                b_departion;
  char ch;
  string str;
  cin >> a >> ta;
  cin >> b >> tb;
  cin >> str;
  istringstream iss(str);
  iss >> n1;
  iss >> ch;
  iss >> n2;
  a_departion = n1 * 60 + n2;
  a_arrival = a_departion + ta;
  b_departion = 5 * 60;
  b_arrival = b_departion + tb;
  while (b_departion < a_arrival && b_departion < 23 * 60 + 59) {
    if (b_arrival > a_departion) {
      cnt++;
    }
    b_departion += b;
    b_arrival = b_departion + tb;
  }
  cout << cnt;
  return 0;
}
