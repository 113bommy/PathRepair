#include <bits/stdc++.h>
using namespace std;
bool cycle;
vector<list<int>> relations;
vector<int> visited(3, -1);
void cycleCheck(int v) {
  visited[v] = 1;
  if (!relations[v].empty() && relations[v].size() == 1) {
    int front = relations[v].front();
    if (visited[front] == -1) {
      cycleCheck(front);
    } else if (visited[front] == 1) {
      cycle = true;
    }
  }
}
int main() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  for (int i = 0; i < 3; i++) {
    list<int> newlist;
    relations.push_back(newlist);
  }
  if (s1[1] == '<') {
    relations[s1[2] - 'A'].push_front(s1[0] - 'A');
  } else {
    relations[s1[0] - 'A'].push_front(s1[2] - 'A');
  }
  if (s2[1] == '<') {
    relations[s2[2] - 'A'].push_front(s2[0] - 'A');
  } else {
    relations[s2[0] - 'A'].push_front(s2[2] - 'A');
  }
  if (s3[1] == '<') {
    relations[s3[2] - 'A'].push_front(s3[0] - 'A');
  } else {
    relations[s3[0] - 'A'].push_front(s3[2] - 'A');
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) visited[j] = -1;
    cycle = false;
    cycleCheck(i);
    if (cycle) {
      cout << "Impossible" << endl;
      return 0;
    }
  }
  char first = 0;
  char second = 0;
  char third = 0;
  for (int i = 0; i < 3; i++) {
    if (relations[i].size() == 0) {
      first = 'A' + i;
    }
  }
  for (int i = 0; i < 3; i++) {
    if (relations[i].size() == 2) {
      third = 'A' + i;
    }
  }
  for (int i = 0; i < 3; i++) {
    if (relations[i].size() == 1) {
      second = 'A' + i;
    }
  }
  cout << first << second << third << endl;
  return 0;
}
