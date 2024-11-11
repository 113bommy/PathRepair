#include <bits/stdc++.h>
using namespace std;
vector<int> vec[100005];
bool vis[1 << 25];
int Gcd[1000005];
int parent[1000005];
int height[1000005];
vector<pair<int, int>> vec1[1000005];
int ans = 0;
void dfs(int node) {
  vis[node] = 1;
  for (int i = 0; i < vec[node].size(); i++) {
    if (!vis[vec[node][i]]) {
      height[vec[node][i]] = height[node] + 1;
      parent[vec[node][i]] = node;
      dfs(vec[node][i]);
    }
  }
}
int divi[20000005];
bool vis1[20000005];
int pre_sum[20000005];
vector<int> prime;
void run() {
  int j = 1;
  for (int i = 2; i < 20000001; i++) {
    if (!vis1[i])
      while (i * j < 20000001) {
        vis1[i * j] = 1;
        divi[i * j] = i;
        j++;
      }
    j = 1;
  }
  for (int i = 2; i < 1000001; i++) {
    if (i == divi[i]) {
      prime.push_back(i);
      pre_sum[i] = 1;
    }
  }
}
long long int countDivisibles(long long int A, long long int B,
                              long long int M) {
  if (A % M == 0) return (B / M) - (A / M) + 1;
  return (B / M) - (A / M);
}
int segmenttree[2000005];
void build(int arr[], int index, int left, int right) {
  if (left == right) {
    segmenttree[index] = arr[left];
  } else {
    int mid = (left + right) / 2;
    build(arr, 2 * index + 1, left, mid);
    build(arr, 2 * index + 2, mid + 1, right);
    segmenttree[index] =
        min(segmenttree[index * 2 + 1], segmenttree[index * 2 + 2]);
  }
}
int Action(int index, int left, int right, int qleft, int qright) {
  if (qleft > qright) {
    return 0;
  }
  if (left == qleft && right == qright) {
    return segmenttree[index];
  }
  int mid = (left + right) / 2;
  return Action(2 * index + 1, left, mid, qleft, min(mid, right)) +
         Action(2 * index + 2, mid + 1, right, max(left, mid + 1), qright);
}
void update(int index, int val, int left, int right) {}
bool check_collinear(int x1, int y1, int x2, int y2, int x3, int y3) {
  int dis1 = abs(x1 - x2) + abs(y1 - y2);
  int dis2 = abs(x1 - x3) + abs(y1 - y3);
  int dis3 = abs(x3 - x2) + abs(y3 - y2);
  if ((dis1 == dis2 + dis3) || (dis2 == dis3 + dis1) || (dis3 == dis1 + dis2))
    return true;
  else
    return false;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    int count = 0;
    int ans = 10;
    for (int i = 0; i < 10; i++) {
      if (str[i] == '?') {
        count++;
      }
    }
    for (int i = 0; i < (1 << count); i++) {
      string check = str;
      int val = i;
      for (int k = 0; k < 10; k++) {
        if (check[k] == '?') {
          if (val % 2) {
            check[k] = '1';
          } else {
            check[k] = '0';
          }
          val /= 2;
        }
      }
      for (int k = 0; k < 10; k++) {
        int odd = 0, even = 0;
        for (int j = 0; j <= k; j++) {
          if (check[j] == '1') {
            if (j % 2) {
              even++;
            } else {
              odd++;
            }
          }
        }
        int odd1 = 0, even1 = 0;
        for (int j = k + 1; j < 10; j++) {
          if (j % 2) {
            even1++;
          } else {
            odd1++;
          }
        }
        if (odd < even && (odd + odd1 < even)) {
          ans = min(k + 1, ans);
        }
        if (odd > even && (odd > even1 + even)) {
          ans = min(k + 1, ans);
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
