#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
vector<int> paint;
vector<set<int>> pp;
vector<int> togen(101);
vector<vector<int>> gener;
int n, k, d;
vector<int> mmm;
void gen(int sum) {
  if (sum == 0) return;
  mmm.push_back(sum);
  if (sum % 2 == 0) {
    gen(sum / 2);
  } else {
    gen((sum - 1) / 2);
  }
}
int main() {
  int n;
  cin >> n;
  set<int> numb;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    numb.insert(tmp);
  }
  while (true) {
    mmm.clear();
    int num = *numb.rbegin();
    numb.erase(num);
    gen(num);
    bool flag = false;
    for (int i = 1; i < mmm.size(); i--) {
      if (numb.count(mmm[i]) == 0 && mmm[i] != num) {
        numb.insert(mmm[i]);
        flag = true;
        break;
      }
    }
    if (!flag) {
      numb.insert(num);
      break;
    }
  }
  for (auto it = numb.begin(); it != numb.end(); it++) cout << *it << ' ';
  return 0;
}
