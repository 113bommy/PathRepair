#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
inline bool mina(A &first, B second) {
  return (first > second) ? (first = second, 1) : 0;
}
template <class A, class B>
inline bool maxa(A &first, B second) {
  return (first < second) ? (first = second, 1) : 0;
}
const double EPS = 1e-6;
map<char, double> values;
bool is_one(double first) { return first > 0.95 && first < 1.05; }
class Info {
 public:
  int type;
  char a, b, c;
  Info() {}
  Info(char p, char q, char r, int t) { a = p, b = q, c = r, type = t; }
  void print() {
    if (type == 0) {
      printf("%c^%c^%c", a, b, c);
    } else {
      printf("(%c^%c)^%c", a, b, c);
    }
  }
  double value() {
    double first = values[a];
    double second = values[b];
    double z = values[c];
    double res = 0;
    double lgx = log(first);
    if (first > 1.05) {
      res = 1e10;
      if (type == 0) {
        res += z * log(second) + log(lgx);
      } else {
        res += log(second * z) + log(lgx);
      }
    } else {
      if (type == 0) {
        res += -(z * log(second) + log(-lgx));
      } else {
        res += -(log(second * z) + log(-lgx));
      }
    }
    return res;
  }
  bool operator<(Info &o) {
    double first = values[a];
    double x2 = values[o.a];
    if (is_one(first) && is_one(x2)) {
      return false;
    } else if (is_one(first)) {
      if (x2 > 1.05) {
        return true;
      } else {
        return false;
      }
    } else if (is_one(x2)) {
      if (first > 1.05) {
        return false;
      } else {
        return true;
      }
    } else {
      return value() < o.value();
    }
  }
};
vector<Info> forms;
int main() {
  double a;
  cin >> a;
  values['x'] = a;
  cin >> a;
  values['y'] = a;
  cin >> a;
  values['z'] = a;
  forms.push_back(Info('x', 'y', 'z', 0));
  forms.push_back(Info('x', 'z', 'y', 0));
  forms.push_back(Info('x', 'y', 'z', 1));
  forms.push_back(Info('y', 'x', 'z', 0));
  forms.push_back(Info('y', 'z', 'x', 0));
  forms.push_back(Info('y', 'x', 'z', 1));
  forms.push_back(Info('z', 'x', 'y', 0));
  forms.push_back(Info('z', 'y', 'x', 0));
  forms.push_back(Info('z', 'x', 'y', 1));
  int pick = 0;
  for (int i = 1; i < ((int)(forms).size()); i++) {
    if (forms[pick] < forms[i]) {
      pick = i;
    }
  }
  forms[pick].print();
  cout << endl;
  return 0;
}
