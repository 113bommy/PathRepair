#include <bits/stdc++.h>
using namespace std;
struct T {
  int index, val;
  string ope;
  T(int index, int val, string s) : index(index), val(val), ope(s) {}
};
bool cmpind(const T &a, const T &b) { return a.index < b.index; }
bool cmpval(const T &a, const T &b) { return a.val < b.val; }
int main() {
  int n, a;
  scanf("%d", &n);
  vector<T> t;
  int ind = 0;
  while (n--) {
    scanf("%d", &a);
    if (a != 0) {
      t.push_back(T(ind++, a, ""));
    }
    int k = t.size();
    if ((a == 0 && !t.empty()) || (a != 0 && n == 0 && !t.empty())) {
      if (k > 3) {
        sort(t.begin(), t.end(), cmpval);
        vector<T>::iterator it;
        for (it = t.begin(); it != t.end() - 3; ++it) it->ope = "pushBack";
        t[k - 1].ope = "pushFront", t[k - 2].ope = "pushQueue",
              t[k - 3].ope = "pushStack";
        sort(t.begin(), t.end(), cmpind);
        for (it = t.begin(); it != t.end(); ++it) cout << it->ope << endl;
      } else if (k == 3)
        printf("pushBack\npushQueue\npushStack\n");
      else if (k == 2)
        printf("pushBack\npushQueue\n");
      else if (k == 1)
        printf("pushBack\n");
      t.clear();
    }
    if (a == 0 && t.empty()) {
      ind = 0;
      if (k >= 3)
        printf("3 popFront popQueue popStack\n");
      else if (k == 2)
        printf("2 popFront popQueue\n");
      else if (k == 1)
        printf("1 popFront\n");
      else
        printf("0\n");
      t.clear();
    }
  }
  return 0;
}
