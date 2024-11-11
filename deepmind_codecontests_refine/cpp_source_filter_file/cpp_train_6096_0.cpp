#include <bits/stdc++.h>
using namespace std;
template <typename T>
T in() {
  char ch;
  T n = 0;
  bool ng = false;
  while (1) {
    ch = getchar();
    if (ch == '-') {
      ng = true;
      ch = getchar();
      break;
    }
    if (ch >= '0' && ch <= '9') break;
  }
  while (1) {
    n = n * 10 + (ch - '0');
    ch = getchar();
    if (ch < '0' || ch > '9') break;
  }
  return (ng ? -n : n);
}
template <typename T>
inline T POW(T B, T P) {
  if (P == 0) return 1;
  if (P & 1)
    return B * POW(B, P - 1);
  else
    return (POW(B, P / 2) * POW(B, P / 2));
}
template <typename T>
inline T Gcd(T a, T b) {
  if (a < 0) return Gcd(-a, b);
  if (b < 0) return Gcd(a, -b);
  return (b == 0) ? a : Gcd(b, a % b);
}
template <typename T>
inline T Lcm(T a, T b) {
  if (a < 0) return Lcm(-a, b);
  if (b < 0) return Lcm(a, -b);
  return a * (b / Gcd(a, b));
}
long long Bigmod(long long base, long long power, long long MOD) {
  long long ret = 1;
  while (power) {
    if (power & 1) ret = (ret * base) % MOD;
    base = (base * base) % MOD;
    power >>= 1;
  }
  return ret;
}
bool isVowel(char ch) {
  ch = toupper(ch);
  if (ch == 'A' || ch == 'U' || ch == 'I' || ch == 'O' || ch == 'E')
    return true;
  return false;
}
template <typename T>
long long int isLeft(T a, T b, T c) {
  return (a.x - b.x) * (b.y - c.y) - (b.x - c.x) * (a.y - b.y);
}
long long ModInverse(long long number, long long MOD) {
  return Bigmod(number, MOD - 2, MOD);
}
bool isConst(char ch) {
  if (isalpha(ch) && !isVowel(ch)) return true;
  return false;
}
int toInt(string s) {
  int sm;
  stringstream second(s);
  second >> sm;
  return sm;
}
int Ok(vector<int> a, vector<int> b) {
  if (b[0] >= a[0] && b[2] <= a[2] && b[1] >= a[1] && b[3] <= a[3]) return 1;
  return 0;
}
vector<int> Dekhi1(int v, vector<int> tp, vector<int> aa) {
  int lo = tp[0], hi = tp[2];
  int ans = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    cout << "? " << tp[0] << " " << tp[1] << " " << mid << " " << tp[3] << endl;
    int x;
    cin >> x;
    vector<int> xx;
    xx.push_back(tp[0]);
    xx.push_back(tp[1]);
    xx.push_back(mid);
    xx.push_back(tp[3]);
    x -= Ok(xx, aa);
    if (x >= v) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  lo = tp[0], hi = ans;
  int ans1 = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    cout << "? " << mid << " " << tp[1] << " " << ans << " " << tp[3] << endl;
    int x;
    cin >> x;
    vector<int> xx;
    xx.push_back(mid);
    xx.push_back(tp[1]);
    xx.push_back(ans1);
    xx.push_back(tp[3]);
    x -= Ok(xx, aa);
    if (x >= v) {
      ans1 = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  lo = tp[1], hi = tp[3];
  int ans2 = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    cout << "? " << ans1 << " " << mid << " " << ans << " " << tp[3] << endl;
    int x;
    cin >> x;
    vector<int> xx;
    xx.push_back(ans1);
    xx.push_back(mid);
    xx.push_back(ans1);
    xx.push_back(tp[3]);
    x -= Ok(xx, aa);
    if (x >= v) {
      ans2 = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  lo = ans2, hi = tp[3];
  int ans3 = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    cout << "? " << ans1 << " " << ans2 << " " << ans << " " << mid << endl;
    int x;
    cin >> x;
    vector<int> xx;
    xx.push_back(ans1);
    xx.push_back(ans2);
    xx.push_back(ans1);
    xx.push_back(mid);
    x -= Ok(xx, aa);
    if (x >= v) {
      ans3 = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  vector<int> a;
  a.push_back(ans1);
  a.push_back(ans2);
  a.push_back(ans);
  a.push_back(ans3);
  return a;
}
vector<int> Dekhi(int v, vector<int> tp) {
  int lo = tp[0], hi = tp[2];
  int ans = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    cout << "? " << tp[0] << " " << tp[1] << " " << mid << " " << tp[3] << endl;
    int x;
    cin >> x;
    if (x >= v) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  lo = tp[0], hi = ans;
  int ans1 = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    cout << "? " << mid << " " << tp[1] << " " << ans << " " << tp[3] << endl;
    int x;
    cin >> x;
    if (x >= v) {
      ans1 = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  lo = tp[1], hi = tp[3];
  int ans2 = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    cout << "? " << ans1 << " " << mid << " " << ans << " " << tp[3] << endl;
    int x;
    cin >> x;
    if (x >= v) {
      ans2 = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  lo = ans2, hi = tp[3];
  int ans3 = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    cout << "? " << ans1 << " " << ans2 << " " << ans << " " << mid << endl;
    int x;
    cin >> x;
    if (x >= v) {
      ans3 = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  vector<int> a;
  a.push_back(ans1);
  a.push_back(ans2);
  a.push_back(ans);
  a.push_back(ans3);
  return a;
}
int main() {
  int n;
  cin >> n;
  vector<int> nw;
  nw.push_back(1);
  nw.push_back(1);
  nw.push_back(n);
  nw.push_back(n);
  vector<int> xx = Dekhi(2, nw);
  vector<int> xy = Dekhi(1, xx);
  vector<int> lst = Dekhi1(1, xx, xy);
  cout << "!";
  for (int i = 0; i < xx.size(); i++) cout << " " << xy[i];
  for (int i = 0; i < xx.size(); i++) cout << " " << lst[i];
  cout << endl;
  return 0;
}
