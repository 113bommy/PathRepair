#include <bits/stdc++.h>
using namespace std;
struct node {
  long long hairs;
  long long annoyance;
  size_t index;
  node(long long hairs, long long annoyance, size_t index)
      : hairs(hairs), annoyance(annoyance), index(index) {}
  node() : hairs(-1), annoyance(-1), index(999999) {}
};
bool compare1(const node& l, const node& r) {
  return (l.annoyance == r.annoyance) ? l.hairs > r.hairs
                                      : l.annoyance < r.annoyance;
}
bool compare2(const node& l, const node& r) {
  return (l.hairs == r.hairs) ? l.annoyance > r.annoyance : l.hairs > r.hairs;
}
bool compare3(const node& l, const node& r) {
  return (l.annoyance == r.annoyance) ? l.hairs > r.hairs
                                      : l.annoyance < r.annoyance;
}
void printNode(node n) { cout << n.index + 1 << " "; }
int main() {
  ios_base::sync_with_stdio(false);
  size_t n;
  cin >> n;
  size_t p;
  cin >> p;
  size_t k;
  cin >> k;
  vector<node> nodes(n);
  for (size_t i = 0; i < n; i++) {
    long long hairs;
    cin >> hairs;
    long long annoyance;
    cin >> annoyance;
    nodes[i] = node(hairs, annoyance, i);
  }
  sort(nodes.begin(), nodes.end(), compare1);
  size_t removeLeastAnnoying = p - k;
  sort(nodes.begin() + removeLeastAnnoying, nodes.end(), compare2);
  sort(nodes.begin() + p, nodes.end(), compare3);
  long long minannoynace = numeric_limits<long long>::max();
  for (size_t i = removeLeastAnnoying; i < removeLeastAnnoying + k; i++) {
    minannoynace = min(minannoynace, nodes[i].annoyance);
    printNode(nodes[i]);
  }
  long long num = 0;
  for (size_t i = p; i < n; i++) {
    if (nodes[i].annoyance >= minannoynace) break;
    num++;
  }
  long long num2 = 0;
  for (size_t i = p + num - 1; i >= p; i--) {
    num2++;
    if (num2 >= removeLeastAnnoying) break;
    printNode(nodes[i]);
  }
  for (size_t i = num2; i < removeLeastAnnoying; i++) printNode(nodes[i]);
  return 0;
}
