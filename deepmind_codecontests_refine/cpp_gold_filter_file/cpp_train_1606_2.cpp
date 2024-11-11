#include <bits/stdc++.h>
using namespace std;
long long POS(long long x) {
  if (x > 0)
    return x;
  else
    return 0;
}
struct shvm {
  long double z, y, x;
  shvm() {}
  shvm(long double z, long double y, long double x) : z(z), y(y), x(x) {}
  shvm operator+(const shvm &p) const {
    return shvm(z + p.z, y + p.y, x + p.x);
  }
  shvm operator-(const shvm &p) const {
    return shvm(z - p.z, y - p.y, x - p.x);
  }
  shvm operator*(long double con) const {
    return shvm(z * con, y * con, x * con);
  }
  shvm operator/(long double con) const {
    return shvm(z / con, y / con, x / con);
  }
  bool operator<(const shvm &rhs) const {
    return make_pair(z, make_pair(y, x)) <
           make_pair(rhs.z, make_pair(rhs.y, rhs.x));
  }
  bool operator==(const shvm &rhs) const {
    return make_pair(z, make_pair(y, x)) ==
           make_pair(rhs.z, make_pair(rhs.y, rhs.x));
  }
};
const bool testing = false;
int n;
void program() {
  cin >> n;
  string res1;
  string res2;
  for (int i = (1); i < ((n / 2) + 1); ++i) {
    res1.push_back('1');
    res2.push_back('1');
  }
  for (int i = (n / 2 + 1); i < (n + 1); ++i) {
    res1.push_back('0');
    res2.push_back('0');
  }
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  int k = n / 2;
  int i = 0;
  int j = 0;
  int cnt = 0;
  while (i < n && j < n && cnt < n) {
    if (a[i] < b[j]) {
      res1[i] = '1';
      i++;
      cnt++;
      continue;
    } else if (b[j] < a[i]) {
      res2[j] = '1';
      j++;
      cnt++;
      continue;
    } else if (a[i] == b[j]) {
      res1[i] = '1';
      res2[j] = '1';
      i++;
      j++;
      cnt += 2;
    }
  }
  cout << res1 << endl;
  cout << res2 << endl;
}
int main() {
  if (!testing) {
    program();
    return 0;
  }
  FILE *fin = NULL;
  fin = fopen("in.txt", "w+");
  fprintf(fin, "4\n9840 9920\n9860 9980\n9930 10020\n10040 10090\n");
  fclose(fin);
  freopen("in.txt", "r", stdin);
  printf("test case(1) => expected : \n");
  printf("1110\n1100\n");
  printf("test case(1) => founded  : \n");
  program();
  fin = fopen("in.txt", "w+");
  fprintf(fin, "4\n9900 9850\n9940 9930\n10000 10020\n10060 10110\n");
  fclose(fin);
  freopen("in.txt", "r", stdin);
  printf("test case(2) => expected : \n");
  printf("1100\n1100\n");
  printf("test case(2) => founded  : \n");
  program();
  return 0;
}
