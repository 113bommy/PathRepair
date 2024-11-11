#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const int N = int(1e5) + 10, SQRT = 320;
vector<int> arr(N);
int cnt[N / SQRT + 10][N], n, q;
deque<int> a[N / SQRT + 10];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = (int)0; i < (int)n; i++) {
    cin >> arr[i];
    a[i / SQRT].push_back(arr[i]);
    cnt[i / SQRT][arr[i]]++;
  }
  cin >> q;
  int lastans = 0;
  for (int i = (int)0; i < (int)q; i++) {
    int choice;
    cin >> choice;
    if (choice == 1) {
      int L, R;
      cin >> L >> R;
      L = (L + lastans - 1 + n) % n;
      R = (R + lastans - 1 + n) % n;
      if (R < L) swap(R, L);
      int boxL = L / SQRT, posL = L % SQRT, boxR = R / SQRT, posR = R % SQRT;
      int x = a[boxR][posR];
      a[boxR].erase(a[boxR].begin() + posR);
      cnt[boxR][x]--;
      a[boxL].insert(a[boxL].begin() + posL, x);
      cnt[boxL][x]++;
      for (int box = boxL; box < boxR; box++) {
        int x = a[box].back();
        a[box].pop_back();
        cnt[box][x]--;
        a[box + 1].push_front(x);
        cnt[box + 1][x]++;
      }
    } else {
      int L, R, K;
      cin >> L >> R >> K;
      L = (L + lastans - 1 + n) % n;
      R = (R + lastans - 1 + n) % n;
      K = (K + lastans - 1 + n) % n + 1;
      if (R < L) swap(R, L);
      int boxL = L / SQRT, posL = L % SQRT, boxR = R / SQRT, posR = R % SQRT;
      int c = 0;
      if (boxL == boxR) {
        for (int pos = posL; pos <= posR; pos++) {
          c += a[boxL][pos] == K;
        }
      } else {
        for (int pos = posL; pos < SQRT; pos++) {
          c += a[boxL][pos] == K;
        }
        for (int pos = 0; pos <= posR; pos++) {
          c += a[boxR][pos] == K;
        }
        for (int box = boxL + 1; box < boxR; box++) {
          c += cnt[box][K];
        }
      }
      lastans = c;
      cout << lastans << endl;
    }
  }
  return 0;
}
