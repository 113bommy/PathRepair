#include <bits/stdc++.h>
using namespace std;
int dx4[] = {-1, 0, 1, 0};
int dy4[] = {0, 1, 0, -1};
int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};
int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void Duxar(int _this_line) {}
bool AreEqual(double a, double b) { return (fabs(a - b) < 1e-10); }
template <class T>
bool GetNr(T &_value) {
  T _sign = 1;
  char ch;
  _value = 0;
  while (!isdigit(ch = getchar())) {
    if (ch == -1) {
      return false;
    }
    ch == '-' ? _sign = -1 : _sign = 1;
  }
  do {
    _value = _value * 10 + (ch - '0');
  } while (isdigit(ch = getchar()));
  _value *= _sign;
  return true;
}
vector<int> target(3), copa(3), permutation = {0, 1, 2};
bool IsValidDate(vector<int> ndate) {
  int day, month, year;
  day = ndate[0];
  month = ndate[1];
  year = ndate[2];
  if (12 < month) {
    return false;
  }
  if (months[month] + (month == 2 && year % 4 == 0) < day) {
    return false;
  }
  return true;
}
bool CheckDate() {
  int i;
  vector<int> newdate(3);
  for (i = 0; i < 3; ++i) {
    newdate[i] = copa[permutation[i]];
  }
  if (!IsValidDate(newdate)) {
    return false;
  }
  if (target[2] - newdate[2] > 18) return true;
  if (target[2] - newdate[2] < 18) return false;
  assert(target[2] - 18 == newdate[2]);
  if (target[1] > newdate[1]) return true;
  if (target[1] < newdate[1]) return false;
  assert(target[1] == newdate[1]);
  if (target[0] >= newdate[0]) return true;
  return false;
}
int main() {
  string fileInput = "sum";
  scanf("%d.%d.%d", &target[0], &target[1], &target[2]);
  scanf("%d.%d.%d", &copa[0], &copa[1], &copa[2]);
  do {
    if (CheckDate()) {
      printf("YES\n");
      return 0;
    }
  } while (next_permutation((permutation).begin(), (permutation).end()));
  printf("NO\n");
  return 0;
}
