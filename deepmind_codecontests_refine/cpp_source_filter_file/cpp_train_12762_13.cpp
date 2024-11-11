#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int> > RED;
priority_queue<pair<int, int> > BLUE;
priority_queue<pair<int, int> > GREEN;
pair<int, pair<int, int> > TAB[200007];
bool used[200007];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int price;
    scanf("%d", &price);
    TAB[i].first = price;
  }
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    TAB[i].second.first = a;
  }
  for (int i = 1; i <= n; i++) {
    int b;
    scanf("%d", &b);
    TAB[i].second.second = b;
  }
  for (int i = 1; i <= n; i++) {
    if (TAB[i].second.first == 1 or TAB[i].second.second == 1) {
      RED.push(make_pair(-TAB[i].first, i));
    }
    if (TAB[i].second.first == 2 or TAB[i].second.second == 2) {
      BLUE.push(make_pair(-TAB[i].first, i));
    }
    if (TAB[i].second.first == 3 or TAB[i].second.second == 3) {
      GREEN.push(make_pair(-TAB[i].first, i));
    }
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int a;
    scanf("%d", &a);
    bool logic = 0;
    if (a == 1) {
      if (!RED.empty()) {
        while (logic == 0 and !RED.empty()) {
          if (used[RED.top().second] == 1) {
            RED.pop();
          } else {
            logic = 1;
            printf("%d ", -RED.top().first);
            used[RED.top().second] = 1;
            RED.pop();
          }
        }
        if (logic == 0) {
          printf("-1 ");
        }
      } else {
        printf("-1 ");
      }
    }
    if (a == 2) {
      if (!BLUE.empty()) {
        while (logic == 0 and !BLUE.empty()) {
          if (used[BLUE.top().second] == 1) {
            BLUE.pop();
          } else {
            logic = 1;
            printf("%d ", -BLUE.top().first);
            used[BLUE.top().second] = 1;
            BLUE.pop();
          }
        }
        if (logic == 0) {
          printf("-1 ");
        }
      } else {
        printf("-1 ");
      }
    }
    if (a == 3) {
      if (!GREEN.empty()) {
        while (logic == 0 and !GREEN.empty()) {
          if (used[GREEN.top().second] == 1) {
            GREEN.pop();
          } else {
            logic = 1;
            printf("%d ", -GREEN.top().first);
            used[GREEN.top().second] = 1;
            GREEN.pop();
          }
        }
        if (logic == 0) {
          printf("-1");
        }
      } else {
        printf("-1 ");
      }
    }
  }
}
