#include <stdio.h>
#include <vector>
#include <algorithm>
int v, e;
struct Edge {
  Edge() {}
  Edge(int from_, int to_, int capacity_, int rev_) : from(from_), to(to_), capacity(capacity_), rev(rev_) {}
  int from;
  int to;
  int capacity;
  int rev;
};

std::vector<Edge> edges[128];

void addEdge(int from, int to, int capacity) {
  int n1 = edges[from].size();
  int n2 = edges[to].size();
  edges[from].push_back(Edge(from, to, capacity, n2));
  edges[to].push_back(Edge(to, from, 0, n1));
}

bool checked[128];
void init_flow() {
  for(int i = 0; i < 128; ++i) {
	checked[i] = false;
  }
}
int flow(int from, int to, int v) {
  if( from == to ) return v;
  checked[from] = true;
  for(Edge& edge : edges[from]) {
	if( checked[edge.to] ) continue;
	int nv = std::min(v, edge.capacity);
	if( nv == 0 ) continue;
	int f = flow(edge.to, to, nv);
	if( f == 0 ) continue;
	edge.capacity -= f;
	edges[edge.to][edge.rev].capacity += f;
	return f;
  }
  return 0;
}

int maximum_flow(int from, int to) {
  int res = 0;
  for(;;) {
	init_flow();
	int v = flow(from, to, (1 << 30));
	if( v == 0 ) break;
	res += v;
  }
  return res;
}

int main() {
  scanf("%d %d", &v, &e);
  for(int i = 0; i < e; ++i) {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	addEdge(a, b, c);
  }

  printf("%d\n", maximum_flow(0, v - 1));

  return 0;
}