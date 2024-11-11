#include <bits/stdc++.h>
using namespace std;
int N, K;
string s;
int get(int low, int high) {
  if (low >= high) return 0;
  while (low < high) {
    int mid = (low + high) >> 1;
    cout << "1 " << mid << ' ' << mid + 1 << endl;
    fflush(stdout);
    cin >> s;
    if (s[0] == 'T')
      high = mid;
    else
      low = mid + 1;
  }
  return low;
}
int check(int x, int y) {
  if ((x <= 0) || (x > N)) return 0;
  if ((y <= 0) || (y > N)) return 0;
  cout << "1 " << x << ' ' << y << endl;
  fflush(stdout);
  cin >> s;
  if (s[0] != 'T') return 0;
  cout << "1 " << y << ' ' << x << endl;
  fflush(stdout);
  cin >> s;
  if (s[0] != 'T') return 0;
  return 1;
}
void print_answer(int x, int y) { cout << "2 " << x << ' ' << y << endl; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> K;
  int x = get(1, N);
  int y = get(1, x - 1);
  int z = get(x + 1, N);
  if (check(x, y))
    print_answer(x, y);
  else if (check(x, z))
    print_answer(x, z);
  else if (check(y, z))
    print_answer(y, z);
}
