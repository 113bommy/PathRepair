#include <bits/stdc++.h>
using namespace std;
class Num {
 public:
  int ID, num, a, b;
};
Num s[100001];
bool cmp_numeric(Num a, Num b) { return a.num < b.num; }
bool cmp_id(Num a, Num b) { return a.ID < b.ID; }
int main() {
  int n, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> s[i].num;
    s[i].ID = i;
  }
  sort(s, s + n, cmp_numeric);
  int deadline = (n + 2) / 3;
  for (i = 0; i < deadline; i++) {
    s[i].a = i;
    s[i].b = s[i].num - i;
  }
  i = deadline;
  deadline += (n - deadline + 1) / 2;
  for (; i < deadline; i++) {
    s[i].a = s[i].num - i;
    s[i].b = i;
  }
  for (i = deadline; i < n; i++) {
    s[i].b = n - i - 1;
    s[i].a = s[i].num - s[i].b;
  }
  sort(s, s + n, cmp_id);
  cout << "YES" << endl;
  for (i = 0; i < n; i++) cout << s[i].a << " ";
  cout << endl;
  for (i = 0; i < n; i++) cout << s[i].b << " ";
  cout << endl;
  return 0;
}
