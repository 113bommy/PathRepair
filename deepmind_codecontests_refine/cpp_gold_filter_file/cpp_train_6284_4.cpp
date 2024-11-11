#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100002];
int head, tail;
int nodesCount, edgesCount;
bool usedNodes[100002] = {false};
vector<int> allNodes;
void readInput() {
  cin >> nodesCount >> edgesCount >> head >> tail;
  int from, to;
  for (int edge = 0; edge < edgesCount; edge++) {
    cin >> from >> to;
    graph[from].push_back(to);
    graph[to].push_back(from);
    if (!usedNodes[from]) {
      allNodes.push_back(from);
      usedNodes[from] = true;
    }
    if (!usedNodes[to]) {
      allNodes.push_back(to);
      usedNodes[to] = true;
    }
  }
}
void printDragon(int dragonHead, int dragonTail) {
  cout << dragonHead << " " << dragonTail << '\n';
  memset(usedNodes, false, sizeof(usedNodes));
  int printed = 1;
  set<int> repeatedNodes;
  for (int i = 0; i < graph[dragonHead].size(); i++)
    usedNodes[graph[dragonHead][i]] = true;
  for (int i = 0; i < graph[dragonTail].size(); i++)
    if (usedNodes[graph[dragonTail][i]])
      repeatedNodes.insert(graph[dragonTail][i]);
  for (int i = 0; i < graph[dragonHead].size(); i++) {
    if (graph[dragonHead][i] != dragonTail &&
        repeatedNodes.count(graph[dragonHead][i]) == 0) {
      if (printed <= head) {
        cout << graph[dragonHead][i] << ' ';
        printed++;
      } else
        break;
    }
  }
  set<int>::iterator repIndex = repeatedNodes.begin();
  if (printed <= head) {
    for (printed; printed <= head; printed++) {
      cout << *repIndex << ' ';
      repIndex++;
    }
  }
  cout << '\n';
  printed = 1;
  for (int i = 0; i < graph[dragonTail].size(); i++) {
    if (graph[dragonTail][i] != dragonHead &&
        repeatedNodes.count(graph[dragonTail][i]) == 0) {
      if (printed <= tail) {
        cout << graph[dragonTail][i] << ' ';
        printed++;
      } else
        break;
    }
  }
  if (printed <= tail) {
    for (printed; printed <= tail; printed++) {
      cout << *repIndex << ' ';
      repIndex++;
    }
  }
}
void findDragon() {
  int headNode, tailNode;
  bool dragonFound = false;
  int dragonHead = -1, dragonTail = -1;
  int node;
  int differentNodes;
  memset(usedNodes, false, sizeof(usedNodes));
  for (int map = 0; map < nodesCount; map++) {
    node = allNodes[map];
    if (graph[node].size() < tail + 1) continue;
    tailNode = node;
    for (int h = 0; h < graph[node].size(); h++) {
      headNode = graph[tailNode][h];
      if (graph[headNode].size() < head + 1) continue;
      memset(usedNodes, false, sizeof(usedNodes));
      dragonFound = true;
      differentNodes = graph[tailNode].size() + graph[headNode].size() - 2;
      for (int i = 0; i < graph[tailNode].size(); i++) {
        usedNodes[graph[tailNode][i]] = true;
      }
      for (int i = 0; i < graph[headNode].size(); i++) {
        if (usedNodes[graph[headNode][i]]) {
          differentNodes--;
        }
      }
      if (differentNodes < head + tail) dragonFound = false;
      if (dragonFound) {
        dragonHead = headNode;
        dragonTail = tailNode;
        break;
      }
    }
    if (dragonFound) break;
  }
  if (dragonFound) {
    cout << "YES\n";
    printDragon(dragonHead, dragonTail);
  } else {
    cout << "NO";
  }
  cout << endl;
}
int main() {
  readInput();
  findDragon();
  return 0;
}
