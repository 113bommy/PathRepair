#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  int group;
  Node *next, *previous;
  Node() { group = 0; }
};
bool acompare(Node *lhs, Node *rhs) { return lhs->data > rhs->data; }
void Add(Node *&presentNode, int data) {
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;
  newNode->previous = presentNode;
  if (presentNode) presentNode->next = newNode;
  presentNode = newNode;
}
void Remove(Node *&list, Node *presentNode) {
  if (presentNode->previous) presentNode->previous->next = presentNode->next;
  if (presentNode->next) presentNode->next->previous = presentNode->previous;
  if (presentNode->previous == NULL) list = presentNode->next;
  delete (presentNode);
}
int main() {
  int k, n;
  cin >> n >> k;
  Node *list = NULL;
  Node *currentList = NULL;
  Node *increaseNode[200000];
  int f[200000];
  map<int, int> a;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    f[i] = num;
    a[num] = 0;
    Add(currentList, num);
    increaseNode[n - num] = currentList;
    if (!list) list = currentList;
  }
  int group = 1;
  for (int i = n; i > 0; i--) {
    if (a[i] != 0) continue;
    Node *next = increaseNode[n - i]->next;
    Node *prev = increaseNode[n - i]->previous;
    a[i] = group;
    for (int j = 0; j < k && next; j++) {
      a[next->data] = group;
      Node *del = next;
      next = next->next;
      Remove(list, del);
    }
    for (int j = 0; j < k && prev; j++) {
      a[prev->data] = group;
      Node *del = prev;
      prev = prev->previous;
      Remove(list, del);
    }
    Remove(list, increaseNode[n - i]);
    if (group == 1)
      group = 2;
    else
      group = 1;
  }
  for (int i = 0; i < n; ++i) cout << a[f[i]] << "  ";
}
