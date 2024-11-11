#include <bits/stdc++.h>
using namespace std;
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
template <typename T>
inline T BigMod(T A, T B) {
  T ret = 1;
  while (B) {
    if (B & 1) ret = (ret * A) % 1000000007;
    A = (A * A) % 1000000007;
    B = B >> 1;
  }
  return ret;
}
template <typename T>
inline T InvMod(T A, T M = 1000000007) {
  return BigMod(A, M - 2);
}
string tostring(long long int res) {
  string curstr = "";
  while (res != 0) {
    long long int temp = (res % 10);
    curstr += ((char)temp + '0');
    res /= 10;
  }
  reverse(curstr.begin(), curstr.end());
  return curstr;
}
long long int toint(string ss) {
  long long int inss = 0;
  for (int i = 0; i < ss.size(); i++) {
    inss = (inss * 10) + ((int)(ss[i] - '0'));
  }
  return inss;
}
int order[16], temp[16], ans, n, red[16], blu[16];
char card[16];
double rand_real() { return (double)rand() / RAND_MAX; }
int calc() {
  int totcost = n, redcard = 0, blucard = 0, rd = 0, bl = 0;
  for (int j = 0; j < n; j++) {
    int i = order[j];
    int reqred = max(red[i] - redcard, 0);
    int reqblu = max(blu[i] - blucard, 0);
    int reqcard = 0;
    reqcard = max(max(reqred - rd, 0), max(reqblu - bl, 0));
    rd += reqcard;
    bl += reqcard;
    rd -= reqred;
    bl -= reqblu;
    totcost += reqcard;
    if (card[i] == 'R')
      redcard++;
    else
      blucard++;
  }
  return totcost;
}
int main() {
  scanf("%d", &n);
  char ch;
  srand(time(0));
  for (int i = 0; i < n; i++) {
    cin >> card[i];
    scanf("%d %d", &red[i], &blu[i]);
  }
  double temperature = 6666667;
  for (int i = 0; i < n; i++) order[i] = i;
  int cur = calc();
  int res = cur;
  for (int lim = 0; lim <= 666667 + 50; lim++) {
    for (int i = 0; i < n; i++) temp[i] = order[i];
    int fs = rand() % n, sn = rand() % n;
    int x;
    x = order[fs], order[fs] = order[sn], order[sn] = x;
    fs = rand() % n, sn = rand() % n;
    x;
    x = order[fs], order[fs] = order[sn], order[sn] = x;
    int next = calc();
    if (res > next) res = next;
    if (cur > next)
      cur = next;
    else {
      double curtemperature = exp((double)-(next - cur) / temperature);
      if (rand_real() <= curtemperature)
        cur = next;
      else {
        for (int i = 0; i < n; i++) order[i] = temp[i];
      }
    }
    if (temperature > 1e-20) temperature *= 0.97;
  }
  printf("%d\n", res);
  return 0;
}
