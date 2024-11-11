#include <bits/stdc++.h>
using namespace std;
int GCD(int a, int b) { return a == 0 ? b : GCD(b % a, a); }
string ntoa(int b) {
  string a = "";
  while (b) {
    a += (b % 10 + '0');
    b /= 10;
  }
  reverse(a.begin(), a.end());
  return a;
}
struct myitem {
  int h;
  int w;
  myitem(int a, int b) {
    h = a;
    w = b;
    if (h > w) {
      int t = h;
      h = w;
      w = t;
    }
  }
};
bool mycompare(myitem a, myitem b) {
  if (a.h == b.h) return a.w < b.w;
  return a.h < b.h;
}
int findrep(int a, int *representative) {
  if (representative[a] != a) {
    return representative[a] = findrep(representative[a], representative);
  } else {
    return a;
  }
}
void unionfind(int x, int y, int *representative) {
  int xp, yp;
  xp = findrep(x, representative);
  yp = findrep(y, representative);
  representative[yp] = xp;
}
class Graph {
  int V;
  list<int> *adj;
  bool isCyclicUtil(int v, bool visited[], bool *rs);

 public:
  Graph(int V);
  void addEdge(int v, int w);
  bool isCyclic();
};
Graph::Graph(int V) {
  this->V = V;
  adj = new list<int>[V];
}
void Graph::addEdge(int v, int w) { adj[v].push_back(w); }
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack) {
  if (visited[v] == false) {
    visited[v] = true;
    recStack[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
      if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
        return true;
      else if (recStack[*i])
        return true;
    }
  }
  recStack[v] = false;
  return false;
}
bool Graph::isCyclic() {
  bool *visited = new bool[V];
  bool *recStack = new bool[V];
  for (int i = 0; i < V; i++) {
    visited[i] = false;
    recStack[i] = false;
  }
  for (int i = 0; i < V; i++)
    if (isCyclicUtil(i, visited, recStack)) return true;
  return false;
}
int setbit(int N, int pos) { return N = N | (1 << pos); }
int resetbit(int N, int pos) { return N = N & (~(1 << pos)); }
int checkbit(int N, int pos) { return N & (1 << pos); }
int countsets(int N) {
  int a = 0;
  for (int i = 1; i <= N; i <<= 1) {
    if (N & i) a++;
  }
  return a;
}
int numbers[1000005];
int tfreq[1000005];
int main() {
  for (int i = 0; i < 1000005; ++i) {
    tfreq[i] = 0;
  }
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &numbers[i]);
  }
  int difnum = 0;
  int bp = 0;
  int fp = -1;
  int mxl = -1;
  int l = -1;
  int r = -1;
  int fflag = 1;
  while (bp < n && fp < n - 1) {
    if (difnum <= k && fflag) {
      fp++;
      if (tfreq[numbers[fp]] == 0) {
        difnum++;
      }
      tfreq[numbers[fp]]++;
      if (difnum == k) {
        if ((fp - bp + 1) > mxl) {
          mxl = fp - bp + 1;
          l = bp + 1;
          r = fp + 1;
        }
      } else if (difnum > k) {
        tfreq[numbers[fp]]--;
        if (tfreq[numbers[fp]] == 0) difnum--;
        fp--;
        fflag = 0;
      }
    } else if (fflag == 0) {
      tfreq[numbers[bp]]--;
      if (tfreq[numbers[bp]] == 0) {
        difnum--;
      }
      bp++;
      if (difnum < k) {
        fflag = 1;
      }
    }
  }
  printf("%d %d\n", l, r);
}
