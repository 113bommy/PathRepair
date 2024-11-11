#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int a, b, c;
  cin >> a >> b >> c;
  int mx = -1;
  for (int i = 0; i < 7; i++) {
    int x = a / 3;
    int y = b / 2;
    int u = c / 2;
    int z = min(x, min(y, u));
    int p = a - 3 * z;
    int q = b - 2 * z;
    int r = c - 2 * z;
    int cnt = 0;
    if (i == 0) {
      if (p != 0) {
        p--;
        cnt++;
        if (q != 0) {
          q--;
          cnt++;
          if (r != 0) {
            r--;
            cnt++;
            if (p != 0) {
              p--;
              cnt++;
              if (r != 0) {
                r--;
                cnt++;
                if (q != 0) {
                  q--;
                  cnt++;
                  if (p != 0) {
                    p--;
                    cnt++;
                  }
                }
              }
            }
          }
        }
      }
    } else if (i == 1) {
      if (q != 0) {
        q--;
        cnt++;
        if (r != 0) {
          r--;
          cnt++;
          if (p != 0) {
            p--;
            cnt++;
            if (r != 0) {
              r--;
              cnt++;
              if (q != 0) {
                q--;
                cnt++;
                if (p != 0) {
                  p--;
                  cnt++;
                  if (p != 0) {
                    p--;
                    cnt++;
                  }
                }
              }
            }
          }
        }
      }
    } else if (i == 2) {
      if (r != 0) {
        r--;
        cnt++;
        if (p != 0) {
          p--;
          cnt++;
          if (r != 0) {
            r--;
            cnt++;
            if (q != 0) {
              q--;
              cnt++;
              if (p != 0) {
                p--;
                cnt++;
                if (p != 0) {
                  p--;
                  cnt++;
                  if (q != 0) {
                    q--;
                    cnt++;
                  }
                }
              }
            }
          }
        }
      }
    } else if (i == 3) {
      if (p != 0) {
        p--;
        cnt++;
        if (r != 0) {
          r--;
          cnt++;
          if (q != 0) {
            q--;
            cnt++;
            if (p != 0) {
              p--;
              cnt++;
              if (p != 0) {
                p--;
                cnt++;
                if (q != 0) {
                  q--;
                  cnt++;
                  if (r != 0) {
                    r--;
                    cnt++;
                  }
                }
              }
            }
          }
        }
      }
    } else if (i == 4) {
      if (r != 0) {
        r--;
        cnt++;
        if (q != 0) {
          q--;
          cnt++;
          if (p != 0) {
            p--;
            cnt++;
            if (p != 0) {
              p--;
              cnt++;
              if (q != 0) {
                q--;
                cnt++;
                if (r != 0) {
                  r--;
                  cnt++;
                  if (p != 0) {
                    p--;
                    cnt++;
                  }
                }
              }
            }
          }
        }
      }
    } else if (i == 5) {
      if (q != 0) {
        q--;
        cnt++;
        if (p != 0) {
          p--;
          cnt++;
          if (p != 0) {
            p--;
            cnt++;
            if (q != 0) {
              q--;
              cnt++;
              if (r != 0) {
                r--;
                cnt++;
                if (p != 0) {
                  p--;
                  cnt++;
                  if (r != 0) {
                    r--;
                    cnt++;
                  }
                }
              }
            }
          }
        }
      }
    } else if (i == 6) {
      if (p != 0) {
        p--;
        cnt++;
        if (p != 0) {
          p--;
          cnt++;
          if (q != 0) {
            q--;
            cnt++;
            if (r != 0) {
              r--;
              cnt++;
              if (p != 0) {
                p--;
                cnt++;
                if (r != 0) {
                  r--;
                  cnt++;
                  if (q != 0) {
                    q--;
                    cnt++;
                  }
                }
              }
            }
          }
        }
      }
    }
    mx = max(mx, z * 7 + cnt);
  }
  cout << mx << endl;
}
