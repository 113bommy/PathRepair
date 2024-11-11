#include <bits/stdc++.h>
using namespace std;
bool canHear[20010][20];
int chatCalled[20];
int ignored[20][20010];
int res[20010];
int main() {
  int N, M, K;
  cin >> N >> M >> K;
  int cur;
  for (int eid = 1; eid <= N; eid++) {
    for (int cid = 1; cid <= M; cid++) {
      cin >> cur;
      canHear[eid][cid] = cur == 1;
      ignored[cid][eid] = 0;
    }
    res[eid] = 0;
  }
  for (int cid = 1; cid <= N; cid++) chatCalled[cid] = 0;
  int sender, chat;
  for (int k = 0; k < K; k++) {
    cin >> sender >> chat;
    chatCalled[chat]++;
    ignored[chat][sender]++;
  }
  for (int cid = 1; cid <= M; cid++) {
    int numChats = chatCalled[cid];
    if (numChats == 0) continue;
    for (int eid = 1; eid <= N; eid++) {
      if (canHear[eid][cid]) {
        res[eid] += numChats - ignored[cid][eid];
      }
    }
  }
  for (int i = 1; i < N; i++) cout << res[i] << " ";
  cout << res[N] << endl;
}
