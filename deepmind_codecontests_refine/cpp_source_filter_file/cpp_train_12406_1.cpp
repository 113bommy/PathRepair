#include <bits/stdc++.h>
using namespace std;
char num[10000 + 10];
char changed[11][10000 + 10];
int n, k;
int _count[11];
struct Fabs {
  int aabs;
  int location;
  char num;
  int aim;
};
Fabs old[10000 + 10];
bool cmp(Fabs a, Fabs b);
void change(int a);
int cmps(int a, int b);
int main() {
  cin >> n >> k;
  cin >> num;
  for (int i = 0; i < 11; i++) _count[i] = 0;
  for (int i = 0; i <= 9; i++) {
    change(i);
  }
  int _max = 0;
  for (int i = 1; i <= 9; i++) {
    if (cmps(i, _max) == 1) _max = i;
  }
  cout << _count[_max] << endl;
  cout << changed[_max] << endl;
  return 0;
}
void change(int a) {
  int j = 0;
  for (int i = 0; i < n; i++) {
    old[j].aabs = abs(int(num[i] - '0') - a);
    old[j].location = i;
    old[j].num = num[i];
    old[j].aim = a;
    j++;
  }
  sort(old, old + j, cmp);
  for (int i = 0; i < k; i++) {
    _count[a] += old[i].aabs;
    changed[a][old[i].location] = (old[i].aim + '0');
  }
  for (int i = k; i < n; i++) changed[a][old[i].location] = old[i].num;
}
bool cmp(Fabs a, Fabs b) {
  if (a.aabs != b.aabs) return a.aabs < b.aabs;
  if (a.num != b.num) return a.num > b.num;
  if (a.num > (b.aim + '0')) return a.location > b.location;
  return a.location < b.location;
}
int cmps(int a, int b) {
  if (_count[a] < _count[b])
    return 1;
  else if (_count[a] > _count[b])
    return 2;
  else {
    if (strcmp(changed[a], changed[b]) < 0)
      return 1;
    else
      return 2;
  }
}
