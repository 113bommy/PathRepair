#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const long double leps = 1e-14;
string a;
string r1, r2;
int cnt[2][100];
int temp[100];
int chk(int a) {
  int res = 0;
  cnt[0][a]--;
  cnt[1][10 - a]--;
  if (cnt[0][a] < 0 || cnt[1][10 - a] < 0) {
    cerr << (("cnt[0][a]")) << " = " << ((cnt[0][a])) << " " << '\n';
    cerr << (("cnt[1][10 - a]")) << " = " << ((cnt[1][10 - a])) << " " << '\n';
    return 0;
  }
  res++;
  for (int i = 0; i <= 9; i++)
    if (cnt[0][i] != 0 && cnt[1][9 - i] != 0) {
      int t = min(cnt[0][i], cnt[1][9 - i]);
      cnt[0][i] -= t;
      cnt[1][9 - i] -= t;
      res += t;
    }
  res += min(cnt[0][0], cnt[1][0]);
  return res;
}
bool cp() {
  for (int i = 0; i < 10; i++) cnt[0][i] = cnt[1][i] = temp[i];
  return 1;
}
void gen(int a) {
  cerr << (("\"H1\"")) << " = " << (("H1")) << " " << '\n';
  cp();
  cerr << (("cnt[1][9]")) << " = " << ((cnt[1][9])) << " " << '\n';
  cerr << (("a")) << " = " << ((a)) << " " << '\n';
  cnt[0][a]--;
  r1 += (char((a) + '0'));
  cnt[1][10 - a]--;
  r2 += (char((10 - a) + '0'));
  for (int i = 0; i <= 9; i++) {
    cerr << (("i")) << " = " << ((i)) << " " << '\n';
    cerr << (("cnt[0][i]")) << " = " << ((cnt[0][i])) << " " << '\n';
    cerr << (("cnt[1][9 - i]")) << " = " << ((cnt[1][9 - i])) << " " << '\n';
    cerr << (("cnt[1][9]")) << " = " << ((cnt[1][9])) << " " << '\n';
    if (cnt[0][i] <= cnt[1][9 - i]) {
      r1 += string(cnt[0][i], (char((i) + '0')));
      r2 += string(cnt[0][i], (char((9 - i) + '0')));
      cnt[1][9 - i] -= cnt[0][i];
      cnt[0][i] -= cnt[0][i];
    } else {
      r1 += string(cnt[1][9 - i], (char((i) + '0')));
      r2 += string(cnt[1][9 - i], (char((9 - i) + '0')));
      cnt[0][i] -= cnt[1][9 - i];
      cnt[1][9 - i] -= cnt[1][9 - i];
    }
  }
  int tmp = min(cnt[0][0], cnt[1][0]);
  for (int i = 0; i < 10; i++)
    cerr << "cnt : " << i << " " << cnt[0][i] << " " << cnt[1][i] << '\n';
  cerr << (("r1")) << " = " << ((r1)) << " " << '\n';
  cerr << (("r2")) << " = " << ((r2)) << " " << '\n';
  cnt[0][0] -= tmp;
  cnt[1][0] -= tmp;
  for (int i = 0; i <= 9; i++)
    if (cnt[0][i] != 0) r1 += string(cnt[0][i], (char((i) + '0')));
  for (int i = 0; i <= 9; i++)
    if (cnt[1][i] != 0) r2 += string(cnt[1][i], (char((i) + '0')));
  reverse(r1.begin(), r1.end());
  reverse(r2.begin(), r2.end());
  r1 += string(tmp, (char((0) + '0')));
  r2 += string(tmp, (char((0) + '0')));
}
int pr(string &a) {
  int res = 0;
  string last;
  for (int i = 0; i < a.size(); i++)
    if (a[i] == '0')
      res++;
    else
      last += a[i];
  a = last;
  return res;
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin >> a;
  for (int i = 0; i < a.size(); i++) temp[a[i] - '0']++;
  int mx = -1;
  for (int i = 1; i <= 5; i++)
    if (cp() && cnt[0][i] != 0) {
      mx = max(mx, chk(i));
      cp();
      cerr << (("chk(i)")) << " = " << ((chk(i))) << " " << '\n';
    }
  if (mx == 0) {
    a += string(pr(a), '0');
    cout << a << '\n' << a << '\n';
    return 0;
  }
  cerr << (("\"HERE\"")) << " = " << (("HERE")) << " " << '\n';
  for (int i = 0; i <= 9; i++)
    cerr << "cnt : " << i << " = " << cnt[0][i] << '\n';
  for (int i = 1; i <= 5; i++)
    if (cp() && cnt[0][i] != 0 && chk(i) == mx) {
      gen(i);
      break;
    }
  cout << r1 << '\n' << r2 << '\n';
  return 0;
}
