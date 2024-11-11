#include <bits/stdc++.h>
using namespace std;
void read() {}
template <class T, class... Arg>
void read(T &x, Arg &&...args) {
  cin >> x;
  read(args...);
}
void print_err() { cerr << "\n"; }
template <class T, class... Arg>
void print_err(T x, Arg &&...args) {
  cerr << x << " ";
  print_err(args...);
}
template <class T>
void print_container(T &cont) {
  for (auto iter : cont) {
    cerr << iter << " ";
  }
  cerr << "\n";
}
template <class T>
void print_container_pair(T &cont) {
  for (auto iter : cont) {
    cerr << iter.first << " " << iter.second << "\n";
  }
  cerr << "\n";
}
template <class T>
void print_container_map(T &cont) {
  for (auto iter : cont) {
    cerr << iter.first << " " << iter.second << "\n";
  }
  cerr << "\n";
}
template <class T>
void debug_arr(T arr, long long int st, long long int en) {
  for (long long int i = st; i < en; ++i) {
    cerr << arr[i] << " ";
  }
  cerr << endl;
}
template <class T>
void read_arr(T arr, long long int n) {
  for (long long int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
}
template <class T>
void read_c(T &arr, long long int n) {
  for (long long int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
}
void CP() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  return;
}
char *stringTOCharArray(string str) {
  long long int n = str.length();
  char *ch = new char[n + 1];
  ;
  strcpy(ch, str.c_str());
  return ch;
}
string intostring(long long int n) { return to_string(n); }
long long int stringtoint(string str) { return stol(str); }
class Graph {
 public:
  list<long long int> *adj_list;
  long long int v;
  Graph(long long int v) {
    this->v = v;
    adj_list = new list<long long int>[v];
  }
  void add_edge(long long int u, long long int v, bool bidirectional = true) {
    adj_list[u].push_back(v);
    if (bidirectional) {
      adj_list[v].push_back(u);
    }
  }
};
const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};
void preprocessing() { return; }
void solve(int faltu) {
  long long int n, m;
  read(n, m);
  pair<long long int, long long int> p1;
  pair<long long int, long long int> p2;
  pair<long long int, long long int> p3;
  long long int count = 0;
  char ch;
  for (long long int i = 0; i < n; ++i) {
    for (long long int j = 0; j < m; ++j) {
      read(ch);
      if (ch == '*') {
        if (count == 0) {
          p1.first = i + 1;
          p1.second = j + 1;
        }
        if (count == 1) {
          p2.first = i + 1;
          p2.second = j + 1;
        }
        if (count == 2) {
          p3.first = i + 1;
          p3.second = j + 1;
        }
        count++;
      }
    }
  }
  if (p1.first == p2.first) {
    if (p1.second == p3.second) {
      cout << p3.first << " " << p2.second << endl;
    } else if (p2.second == p3.second) {
      cout << p3.first << " " << p1.second << endl;
    }
  } else if (p1.first == p3.first) {
    if (p1.second == p2.second) {
      cout << p2.first << " " << p3.second << endl;
    } else if (p2.second == p3.second) {
      cout << p2.first << " " << p1.second << endl;
    }
  } else if (p2.first == p3.first) {
    if (p1.second == p3.second) {
      cout << p1.first << " " << p2.second << endl;
    } else if (p1.second == p3.second) {
      cout << p1.first << " " << p2.second << endl;
    }
  }
  return;
}
int main() {
  CP();
  int i = 1;
  preprocessing();
  solve(i);
  return 0;
}
