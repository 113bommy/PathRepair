#include <bits/stdc++.h>
struct Vector {
  int32_t x, y;
  Vector(int32_t pX = 0, int32_t pY = 0) : x(pX), y(pY) {}
  friend Vector operator+(const Vector &a, const Vector &b) {
    return Vector(a.x + b.x, a.y + b.y);
  }
  friend Vector operator-(const Vector &a, const Vector &b) {
    return Vector(a.x - b.x, a.y - b.y);
  }
  friend int32_t operator*(const Vector &a, const Vector &b) {
    return a.x * b.y - a.y * b.x;
  }
};
std::ostream &operator<<(std::ostream &s, const Vector &v) {
  return s << "(" << v.x << ", " << v.y << ")";
}
struct Vertex {
  std::vector<Vertex *> edges;
  bool visited;
  Vertex() : visited(false) {}
  void dfs() {
    visited = true;
    for (Vertex *v : edges) {
      if (!v->visited) {
        v->dfs();
      }
    }
  }
};
struct Node {
  Vector vec;
  bool crossSide;
  Vertex *vert;
  Node(Vector pVec = Vector(), bool pS = false, Vertex *pVert = nullptr)
      : vec(pVec), crossSide(pS), vert(pVert) {}
};
std::vector<Node> polygon;
std::vector<Node> intersect;
std::vector<Vertex> graph;
int32_t xl, yl, xh, yh;
uint32_t rect_side(const Vector &v) {
  if (v.y == yl) {
    return 0;
  } else if (v.x == xh) {
    return 1;
  } else if (v.y == yh) {
    return 2;
  } else {
    return 3;
  }
}
bool intersect_cmp(const Node &aN, const Node &bN) {
  const Vector &a = aN.vec;
  const Vector &b = bN.vec;
  uint32_t aSide = rect_side(a);
  uint32_t bSide = rect_side(b);
  if (aSide != bSide) {
    return aSide < bSide;
  }
  if (aSide == 0) {
    return a.x < b.x;
  } else if (aSide == 1) {
    return a.y < b.y;
  } else if (aSide == 2) {
    return a.x > b.x;
  } else {
    return a.y > b.y;
  }
}
void input() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> xl >> yh >> xh >> yl;
  uint32_t n;
  std::cin >> n;
  polygon.resize(n);
  for (auto &v : polygon) {
    std::cin >> v.vec.x >> v.vec.y;
  }
}
bool inside(Vector v) {
  return ((v.x > xl) && (v.x < xh) && (v.y > yl) && (v.y < yh));
}
std::vector<Node> calc_intersect(Vector a, Vector b) {
  bool rev = false;
  std::vector<Node> ans;
  if (a.y == b.y) {
    if ((a.y <= yl) || (yh <= a.y)) {
      return ans;
    }
    if (a.x > b.x) {
      std::swap(a, b);
      rev = true;
    }
    if ((a.x < xh) && (xh <= b.x)) {
      ans.push_back(Node(Vector(xh, a.y), !rev));
    }
    if ((a.x <= xl) && (xl < b.x)) {
      ans.push_back(Node(Vector(xl, a.y), rev));
    }
  } else {
    if ((a.x <= xl) || (xh <= a.x)) {
      return ans;
    }
    if (a.y > b.y) {
      std::swap(a, b);
      rev = true;
    }
    if ((a.y < yh) && (yh <= b.y)) {
      ans.push_back(Node(Vector(a.x, yh), !rev));
    }
    if ((a.y <= yl) && (yl < b.y)) {
      ans.push_back(Node(Vector(a.x, yl), rev));
    }
  }
  return ans;
}
void build_graph() {
  graph.reserve(polygon.size() * 3);
  for (uint32_t i = 0; i < polygon.size(); i++) {
    if (inside(polygon[i].vec)) {
      graph.push_back(Vertex());
      polygon[i].vert = &graph.back();
    }
  }
  for (uint32_t i = 0; i < polygon.size(); i++) {
    uint32_t j = i + 1 < polygon.size() ? i + 1 : 0;
    Node &c = polygon[j];
    Node &p = polygon[i];
    if ((c.vert != nullptr) && (p.vert != nullptr)) {
      c.vert->edges.push_back(p.vert);
      p.vert->edges.push_back(c.vert);
    }
    std::vector<Node> curInter = calc_intersect(p.vec, c.vec);
    if (curInter.empty()) {
      continue;
    }
    for (Node &n : curInter) {
      graph.push_back(Vertex());
      n.vert = &graph.back();
    }
    if (curInter.size() == 1) {
      if (c.vert != nullptr) {
        c.vert->edges.push_back(curInter[0].vert);
        curInter[0].vert->edges.push_back(c.vert);
      } else {
        p.vert->edges.push_back(curInter[0].vert);
        curInter[0].vert->edges.push_back(p.vert);
      }
    } else {
      curInter[0].vert->edges.push_back(curInter[1].vert);
      curInter[1].vert->edges.push_back(curInter[0].vert);
    }
    for (Node &n : curInter) {
      intersect.push_back(n);
    }
  }
  std::sort(intersect.begin(), intersect.end(), intersect_cmp);
  for (uint32_t i = 0; i < intersect.size(); i++) {
    if (intersect[i].crossSide) {
      Vertex *v1 = intersect[i].vert;
      Vertex *v2 = intersect[i + 1 < intersect.size() ? i + 1 : 0].vert;
      v1->edges.push_back(v2);
      v2->edges.push_back(v1);
    }
  }
}
int64_t cross_area() {
  int64_t ans = 0;
  for (uint32_t i = 0; i < polygon.size(); i++) {
    Vector a = polygon[i].vec;
    Vector b = polygon[i + 1 == polygon.size() ? 0 : i + 1].vec;
    if (a.x == b.x) {
      continue;
    }
    int64_t mult = a.x > b.x ? 1 : -1;
    int32_t x1 = std::min(a.x, b.x);
    int32_t x2 = std::max(a.x, b.x);
    x1 = std::max(x1, xl);
    x2 = std::min(x2, xh);
    if (x1 >= x2) {
      continue;
    }
    int64_t xSide = (x2 - x1) * mult;
    int64_t ySide = 0;
    if (a.y > yh) {
      ySide = yh - yl;
    } else if (a.y > yl) {
      ySide = a.y - yl;
    } else {
      ySide = 0;
    }
    ans += xSide * ySide;
  }
  return ans;
}
uint32_t calc_ans() {
  uint32_t ans = 0;
  int64_t rectArea = (int64_t)(xh - xl) * (yh - yl);
  if (cross_area() == rectArea) {
    return 1;
  }
  for (Vertex &v : graph) {
    if (!v.visited) {
      ans++;
      v.dfs();
    }
  }
  return ans;
}
int main() {
  input();
  build_graph();
  std::cout << calc_ans() << "\n";
}
