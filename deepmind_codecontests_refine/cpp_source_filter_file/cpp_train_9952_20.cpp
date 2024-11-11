#include <bits/stdc++.h>
using namespace std;
long long num, pi = 1000000000ll + 7ll;
long long arr[130][7], kola[7];
int solved(int t) {
  if (t == pi) return 0;
  return 1;
}
long long get_ball(int x) {
  if (num >= kola[x] * 32) return 3000;
  if (num >= kola[x] * 16) return 2500;
  if (num >= kola[x] * 8) return 2000;
  if (num >= kola[x] * 4) return 1500;
  if (num >= kola[x] * 2) return 1000;
  return 500;
}
long long get_points(int id) {
  long long s = 0;
  for (int i = 1; i <= 5; i++) {
    if (arr[id][i] < pi) s += get_ball(i) - ((get_ball(i) / 250) * arr[id][i]);
  }
  return s;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n, t;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i][1] >> arr[i][2] >> arr[i][3] >> arr[i][4] >> arr[i][5];
    if (arr[i][1] == -1) arr[i][1] = pi;
    if (arr[i][2] == -1) arr[i][2] = pi;
    if (arr[i][3] == -1) arr[i][3] = pi;
    if (arr[i][4] == -1) arr[i][4] = pi;
    if (arr[i][5] == -1) arr[i][5] = pi;
    kola[1] += solved(arr[i][1]);
    kola[2] += solved(arr[i][2]);
    kola[3] += solved(arr[i][3]);
    kola[4] += solved(arr[i][4]);
    kola[5] += solved(arr[i][5]);
  }
  num = n;
  t = 0;
  while (get_points(1) <= get_points(2)) {
    if ((arr[2][1] <= arr[1][1]) && (arr[1][1] < pi)) kola[1]++;
    if ((arr[2][2] <= arr[1][2]) && (arr[1][2] < pi)) kola[2]++;
    if ((arr[2][3] <= arr[1][3]) && (arr[1][3] < pi)) kola[3]++;
    if ((arr[2][4] <= arr[1][4]) && (arr[1][4] < pi)) kola[4]++;
    if ((arr[2][5] <= arr[1][5]) && (arr[1][5] < pi)) kola[5]++;
    num++;
    t++;
    if (t > 1000) {
      cout << "-1";
      return 0;
    }
  }
  cout << t << '\n';
  return 0;
}
