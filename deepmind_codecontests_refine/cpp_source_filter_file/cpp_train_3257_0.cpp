#include <bits/stdc++.h>
using namespace std;
struct edge {
  int from, to, w;
  edge(int a, int b, int c) {
    from = a;
    to = b;
    w = c;
  }
};
struct s_node {
  int id, dis;
  s_node(int a, int b) {
    id = a;
    dis = b;
  }
  bool operator<(const s_node& a) const { return dis > a.dis; }
};
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
typedef struct {
  int id;
  long long num;
} node;
node arr[200010];
vector<node> ans;
bool cmp(const node& a, const node& b) { return a.num > b.num; }
int main(int argc, const char* argv[]) {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n, w;
    cin >> n >> w;
    ans.clear();
    int mid = (w + 1) / 2;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i].num;
      arr[i].id = i;
    }
    sort(arr + 1, arr + 1 + n, cmp);
    long long sum = 0;
    int flag = 0;
    for (int i = 1; i <= n; i++) {
      if (arr[i].num >= mid && arr[i].num <= w) {
        cout << "1\n" << arr[i].id << "\n";
        flag = 1;
        break;
      } else if (arr[i].num < mid) {
        sum += arr[i].num;
        ans.push_back(arr[i]);
        if (sum >= mid) {
          flag = 1;
          cout << ans.size() << "\n";
          for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].id << " ";
          }
          cout << "\n";
          break;
        }
      }
    }
    if (flag == 0) cout << "-1\n";
  }
  return 0;
}
