#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int first = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') first = -first;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  x *= first;
}
int n;
const int MAXN = 888;
int ans[MAXN];
bool odd[MAXN], used[MAXN];
pair<int, int> pos[5];
void get_1_n() {
  for (int i = 1; i <= n; i++) {
    cout << "? " << n - 1;
    for (int j = 1; j <= n; j++) {
      if (i != j) cout << " " << j;
    }
    cout << endl;
    int res;
    cin >> res;
    if (res) {
      if (pos[1].first)
        pos[1].second = i;
      else
        pos[1].first = i;
    }
  }
  return;
}
void get_odd() {
  for (int i = 1; i <= n; i++) {
    if (i != pos[1].first) {
      cout << "? " << 2 << " " << i << " " << pos[1].first << endl;
      cin >> odd[i];
    }
  }
}
void get_234() {
  for (int k = 1; k <= 3 && k <= n / 2; k++) {
    for (int i = 1; i <= n; i++) {
      if (used[i]) continue;
      cout << "? " << n - k * 2 - 1;
      for (int j = 1; j <= n; j++) {
        if (i != j && used[j] == 0) cout << " " << j;
      }
      cout << endl;
      int res;
      cin >> res;
      if (res) {
        if (odd[i] ^ (k % 2 == 0))
          pos[k + 1].second = i;
        else
          pos[k + 1].first = i;
      }
    }
    used[pos[k + 1].first] = used[pos[k + 1].second] = true;
  }
}
int get3(int x) {
  int res;
  cout << '?' << ' ' << 3 << ' ' << x << ' ';
  cout << pos[1].first << ' ' << pos[2].first << endl;
  read(res);
  if (res) return 0;
  cout << '?' << ' ' << 3 << ' ' << x << ' ';
  cout << pos[2].first << ' ' << pos[3].first << endl;
  read(res);
  if (res) return 1;
  return 2;
}
int get5(int x) {
  int res;
  bool mark[5];
  memset(mark, false, sizeof(mark));
  for (int i = 1; i <= 4; i++) {
    cout << "? 5 " << x << ' ' << pos[1].second << ' ' << pos[2].second << ' '
         << pos[3].second << ' ';
    cout << pos[i].first << endl;
    int value = (5 - (3 * n - 3 + i) % 5) % 5;
    cin >> res;
    if (res) return value;
    mark[value] = true;
  }
  for (int i = 0; i <= 4; i++)
    if (!mark[i]) return i;
}
int get7(int x) {
  int res;
  bool mark[7];
  int cnt = 0;
  memset(mark, false, sizeof(mark));
  for (int i = 1; i <= 4 && cnt <= 5; i++)
    for (int j = 1; j <= 4 && cnt <= 5; j++) {
      int value = (7 - (n * 4 + 4 - i - (n - j + 1)) % 7) % 7;
      if (mark[value]) continue;
      cout << '?' << ' ' << 7 << ' ' << x << ' ';
      for (int k = 1; k <= 4; k++)
        if (k != i) cout << pos[k].first << ' ';
      for (int k = 1; k <= 4; k++)
        if (k != j) cout << pos[k].second << ' ';
      cout << endl;
      read(res);
      if (res) return value;
      mark[value] = true, cnt++;
    }
  for (int i = 0; i <= 6; i++)
    if (!mark[i]) return i;
}
int get8(int x) {
  int res;
  int ans = odd[x];
  for (int i = 1; i <= 4; i++) {
    int value = (4 - (10 - i) % 4) % 4;
    if (value == ans) {
      cout << '?' << ' ' << 4 << ' ' << x << ' ';
      for (int k = 1; k <= 4; k++)
        if (k != i) cout << pos[k].first << ' ';
      cout << endl;
      read(res);
      if (res)
        ans = ans;
      else
        ans = ans + 2;
      break;
    }
  }
  for (int i = 1; i <= 4; i++) {
    int value = (8 - (n * 4 + 4 - i) % 8) % 8;
    if (value == ans || value == ans + 4) {
      cout << '?' << ' ' << 8 << ' ' << x << ' ';
      for (int k = 1; k <= 4; k++) {
        if (k != i) cout << pos[k].first << ' ';
        cout << pos[k].second << ' ';
      }
      cout << endl;
      read(res);
      if (res ^ (value == ans))
        ans = ans + 4;
      else
        ans = ans;
      break;
    }
  }
  return ans;
}
void Output() {
  if (ans[1] > n / 2) {
    cout << "!";
    for (int i = 1; i <= n; i++) cout << " " << n - ans[i] + 1;
    cout << endl;
  } else {
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << " " << ans[i];
    cout << endl;
  }
  return;
}
int main() {
  cin >> n;
  get_1_n();
  used[pos[1].first] = used[pos[1].second] = true;
  odd[pos[1].first] = true;
  get_odd();
  get_234();
  for (int i = 1; i <= 4 && i <= n / 2; i++) {
    ans[pos[i].first] = i;
    ans[pos[i].second] = n + 1 - i;
  }
  if (n <= 8) {
    Output();
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (ans[i]) continue;
    int t = get3(i);
    int first = get5(i);
    int second = get7(i);
    int e = get8(i);
    for (int j = 1; j <= n; j++)
      if (j % 3 == t && j % 5 == first && j % 7 == second && j % 8 == e) {
        ans[i] = j;
        break;
      }
  }
  Output();
  return 0;
}
