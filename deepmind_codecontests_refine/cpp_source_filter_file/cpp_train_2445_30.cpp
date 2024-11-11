#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& os, vector<T> xs) {
  for (T x : xs) os << x << ' ';
  return os;
}
template <class S, class T>
ostream& operator<<(ostream& os, pair<S, T> st) {
  os << "(" << st.first << "," << st.second << ")";
  return os;
}
long long A, B;
long long l, t, m;
long long hoge(long long x) { return (A + B * (x - 1)); }
long long sm(long long b) { return (A + hoge(b)) * b / 2; }
bool f(long long r) {
  long long height = A + B * (r - 1);
  if (t < height) return false;
  long long num = sm(r) - sm(l - 1);
  {
    if (false) {
      {
        if (false) {
          cout << "r"
               << ": " << r << "\t";
        }
      };
      {
        if (false) {
          {
            if (false) {
              cout << "num"
                   << ": " << num << "\t";
            }
          };
          {
            if (false) {
              {
                if (false) {
                  cout << "t * min(m, r + 1 - l)"
                       << ": " << t * min(m, r + 1 - l) << "\t";
                }
              };
              cout << endl;
            }
          };
        }
      };
    }
  };
  return (num <= t * min(m, r + 1 - l));
}
int main(void) {
  int x;
  cin >> A >> B >> x;
  while (x-- > 0) {
    cin >> l >> t >> m;
    {
      if (false) {
        {
          if (false) {
            cout << "l"
                 << ": " << l << "\t";
          }
        };
        {
          if (false) {
            {
              if (false) {
                cout << "t"
                     << ": " << t << "\t";
              }
            };
            {
              if (false) {
                {
                  if (false) {
                    cout << "m"
                         << ": " << m << "\t";
                  }
                };
                cout << endl;
              }
            };
          }
        };
      }
    };
    if (!f(l)) {
      cout << -1 << endl;
      continue;
    }
    int left = l, right = 1000000;
    while (right - left > 1) {
      {
        if (false) {
          {
            if (false) {
              cout << "right"
                   << ": " << right << "\t";
            }
          };
          {
            if (false) {
              {
                if (false) {
                  cout << "left"
                       << ": " << left << "\t";
                }
              };
              cout << endl;
            }
          };
        }
      };
      int md = (right + left) / 2;
      if (f(md))
        left = md;
      else
        right = md;
    }
    cout << left << endl;
  }
  return 0;
}
