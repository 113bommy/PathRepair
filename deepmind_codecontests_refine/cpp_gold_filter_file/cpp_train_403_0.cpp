#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 25

class Task {
public:
  int d, lim;
  Task(int d = 0, int lim = 0) : d(d), lim(lim) {}
  bool operator < ( const Task &t ) const {
    if( lim == t.lim ) return d < t.d;
    return lim < t.lim;
  }
};

int main() {
  int n;
  Task T[MAX];
  bool success;
  int cur;

  while(cin >> n && n) {
    for(int i = 0; i < n; i++) {
      cin >> T[i].d >> T[i].lim;
    }
    sort(T, T+n);
    success = true;
    cur = 0;
    for(int i = 0; i < n && success; i++) {
      cur += T[i].d;
      if(T[i].lim < cur) success = false;
    }
    if(success) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  return 0;
}