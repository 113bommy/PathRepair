#include <bits/stdc++.h>
using namespace std;
struct Node {
  int number, last, value;
};
bool operator<(Node a, Node b) { return a.value > b.value; }
vector<int> route[3000];
bool visited[3000];
bool finded = false;
bool circled = false;
int repeat_Point = -1;
int circleNode[3000];
bool is_circle[3000];
int circle_cnt = 0;
int max_num = -1;
void dfs(Node now) {
  for (int i = 0; i < route[now.number].size(); ++i) {
    if (visited[route[now.number][i]]) {
      if (now.last != route[now.number][i]) {
        finded = true;
        repeat_Point = route[now.number][i];
        circle_cnt++;
        circleNode[circle_cnt] = now.number;
        is_circle[now.number] = true;
        return;
      }
    } else {
      visited[route[now.number][i]] = true;
      dfs(Node{route[now.number][i], now.number});
      if (finded) {
        if (!circled) {
          circle_cnt++;
          circleNode[circle_cnt] = now.number;
          is_circle[now.number] = true;
        }
        if (now.number == repeat_Point) {
          circled = true;
        }
        return;
      }
    }
  }
}
int dis[2000];
int dij_visited[2000];
void dij() {
  for (int i = 1; i <= circle_cnt; ++i) {
    for (int j = 0; j < route[circleNode[i]].size(); ++j) {
      if (!is_circle[route[circleNode[i]][j]])
        route[max_num].push_back(route[circleNode[i]][j]);
    }
    dij_visited[circleNode[i]] = true;
  }
  priority_queue<Node> q;
  Node first;
  first.number = max_num;
  first.value = 0;
  q.push(first);
  dij_visited[max_num] = true;
  while (!q.empty()) {
    Node now = q.top();
    q.pop();
    for (int i = 0; i < route[now.number].size(); ++i) {
      if (!dij_visited[route[now.number][i]]) {
        dis[route[now.number][i]] = now.value + 1;
        Node next;
        next.number = route[now.number][i];
        next.value = now.value + 1;
        q.push(next);
        dij_visited[next.number] = true;
      }
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    route[x].push_back(y);
    route[y].push_back(x);
    max_num = max(max_num, max(x, y));
  }
  max_num++;
  dfs(Node{1, -1});
  dij();
  for (int i = 1; i < max_num; i++) {
    printf("%d ", dis[i]);
  }
  return 0;
}
