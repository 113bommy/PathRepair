#include <bits/stdc++.h>
using namespace std;
istream* pin;
intmax_t konstansmod = (1e9) + 7;
template <typename T>
vector<T> read(int num = -1, int szorzo = 1, istream& in = *pin) {
  vector<T> container;
  if (num == -1) in >> num;
  num *= szorzo;
  for (int i = 0; i < num; i++) {
    T q;
    in >> q;
    container.push_back(q);
  }
  return container;
}
struct printer {
  ostream* o;
  printer(ostream& a = cout) : o(&a) {}
  void pr() { *o << "\n"; }
  template <typename T>
  void pr(T intmax_t) {
    *o << std::setprecision(9) << intmax_t << "\n";
  }
  template <typename T>
  void pr(vector<T> intmax_t) {
    for (T w : intmax_t) pr(w);
    pr();
  }
  template <typename T, typename... Args>
  void pr(T value, Args... args) {
    pr(value);
    pr(args...);
  }
};
template <typename H1>
void show(std::ostream& out, const char* label, H1&& value) {
  out << label << "=";
  printer(out).pr(value);
}
template <typename H1, typename... T>
void show(std::ostream& out, const char* label, H1&& value, T&&... rest) {
  const char* pcomma = strchr(label, ',');
  out.write(label, pcomma - label) << "=";
  printer(out).pr(value);
  show(out, pcomma + 1, std::forward<T>(rest)...);
}
void print(bool b) { cout << (b ? "Yes" : "No") << "\n"; }
void solve();
int main(int argc, char** argv) {
  srand((unsigned)time(NULL));
  ifstream* argfile = NULL;
  string filename = "";
  if (argc >= 2 && filename.length() == 0) filename = argv[1];
  if (filename.length() > 0) {
    argfile = new ifstream(filename);
    if (!argfile->is_open()) {
      cerr << "file cant be opened,exiting. Filename:" << filename << "\n";
      cerr << "Error: " << strerror(errno) << "\n";
      return 1;
    }
  }
  if (argfile) std::cin.rdbuf(argfile->rdbuf());
  istream& myfile = argfile ? *argfile : cin;
  pin = &myfile;
  int num;
  solve();
  return 0;
  myfile >> num;
  for (int i = 0; i < num; i++) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }
  return 0;
}
void solve() {
  vector<intmax_t> a = read<intmax_t>();
  intmax_t n = a.size();
  set<intmax_t> rosszpontok;
  set<intmax_t> ketpontos;
  for (int i = 0; i < n; i++) {
    intmax_t bal = 0;
    if (i > 0) {
      if (i % 2 == 1) {
        if (a[i - 1] >= a[i]) bal = 1;
      } else if (a[i - 1] <= a[i])
        bal = 1;
    }
    intmax_t jobb = 0;
    if (i + 1 < n) {
      if (i % 2 == 1) {
        if (a[i] <= a[i + 1]) jobb = 1;
      } else if (a[i] >= a[i + 1])
        jobb = 1;
    }
    if (bal || jobb) rosszpontok.insert(i);
    if (bal && jobb) ketpontos.insert(i);
  }
  intmax_t ret = 0;
  if (rosszpontok.size() <= 6)
    for (auto i2 : rosszpontok) {
      for (int j = 0; j < n; j++)
        if (i2 != j) {
          if (j < i2 && rosszpontok.find(j) != rosszpontok.end()) continue;
          intmax_t temp = a[i2];
          a[i2] = a[j];
          a[j] = temp;
          bool bad = false;
          auto rosszpontok2 = rosszpontok;
          rosszpontok2.insert(j);
          for (auto i : rosszpontok2) {
            intmax_t bal = 0;
            if (i > 0) {
              if (i % 2 == 1) {
                if (a[i - 1] >= a[i]) bad = true;
              } else if (a[i - 1] <= a[i])
                bad = true;
            }
            intmax_t jobb = 0;
            if (i + 1 < n) {
              if (i % 2 == 1) {
                if (a[i] <= a[i + 1]) bad = true;
              } else if (a[i] >= a[i + 1])
                bad = true;
            }
            if (bad) break;
          }
          if (!bad) ret++;
          a[j] = a[i2];
          a[i2] = temp;
        }
    }
  else {
  };
  do {
    printer().pr(ret);
  } while (false);
}
