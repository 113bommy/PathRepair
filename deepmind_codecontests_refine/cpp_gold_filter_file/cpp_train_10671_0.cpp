#include <bits/stdc++.h>
using namespace std;
struct Triple {
  int first;
  int second;
  int third;
  Triple(int first, int second, int third) {
    this->first = first;
    this->second = second;
    this->third = third;
  }
  bool operator<(const Triple other) const {
    if (first == other.first) {
      if (second == other.second) {
        return third < other.third;
      } else {
        return second < other.second;
      }
    } else {
      return first < other.first;
    }
  }
};
class Searcher {
  const set<Triple>& restricted;
  const vector<vector<int> >& roads;
  set<pair<int, int> > visited;
  map<pair<int, int>, pair<int, int> > previous;
  queue<pair<int, int> > q;
  int final;

 public:
  Searcher(const set<Triple>& restricted, const vector<vector<int> >& roads,
           size_t final)
      : restricted(restricted), roads(roads), final(final) {}
  bool search() {
    previous[pair<int, int>(-1, 1)] = pair<int, int>(-1, -1);
    q.push(pair<int, int>(-1, 1));
    while (!q.empty()) {
      pair<int, int> edge(q.front());
      q.pop();
      if (edge.second == final) {
        printResult(edge);
        return true;
      }
      addNeighbours(edge);
    }
    return false;
  }

 private:
  void addNeighbours(pair<int, int> edge) {
    int pred = edge.first;
    int cur = edge.second;
    for (size_t i = 0; i < roads[cur].size(); ++i) {
      int next = roads[cur][i];
      if (!isVisited(cur, next) && !isRestricted(pred, cur, next)) {
        pair<int, int> next_edge(cur, next);
        q.push(next_edge);
        visited.insert(next_edge);
        previous[next_edge] = edge;
      }
    }
  }
  bool isRestricted(int first, int second, int third) {
    return restricted.find(Triple(first, second, third)) != restricted.end();
  }
  bool isVisited(int source, int destination) {
    return visited.find(pair<int, int>(source, destination)) != visited.end();
  }
  void printResult(pair<int, int> edge) {
    stack<int> vertices;
    while (edge.second != -1) {
      vertices.push(edge.second);
      edge = previous[edge];
    }
    cout << vertices.size() - 1 << endl;
    while (!vertices.empty()) {
      cout << vertices.top() << ' ';
      vertices.pop();
    }
    cout << endl;
  }
};
int main() {
  set<Triple> restricted;
  size_t towns;
  size_t roads;
  size_t restrictions;
  cin >> towns;
  cin >> roads;
  cin >> restrictions;
  vector<vector<int> > road(towns + 1);
  size_t t1;
  size_t t2;
  for (size_t i = 0; i < roads; ++i) {
    cin >> t1;
    cin >> t2;
    road[t1].push_back(t2);
    road[t2].push_back(t1);
  }
  size_t r1;
  size_t r2;
  size_t r3;
  for (size_t i = 0; i < restrictions; ++i) {
    cin >> r1;
    cin >> r2;
    cin >> r3;
    restricted.insert(Triple(r1, r2, r3));
  }
  Searcher s(restricted, road, towns);
  if (!s.search()) {
    cout << "-1" << endl;
  }
  return 0;
}
