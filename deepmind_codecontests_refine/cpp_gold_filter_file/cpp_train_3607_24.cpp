#include <bits/stdc++.h>
using namespace std;
const int N = 2000 + 1;
char s[N], t[N];
struct arbol {
  char c;
  int n_izq, n_der;
  arbol *padre, *izq, *der;
  bool reversa;
  int n() { return 1 + n_izq + n_der; }
  bool es_izq() { return padre && padre->izq == this; }
  bool es_der() { return padre && padre->der == this; }
  bool es_raiz() { return !padre; }
  bool tiene_abuelo() { return padre && padre->padre; }
  void rota() {
    aplica_reversa(false);
    arbol *x = this;
    arbol *p = padre;
    bool x_es_izq = es_izq();
    x->padre = p->padre;
    if (p->padre) {
      arbol *a = p->padre;
      if (p->es_izq()) {
        a->izq = x;
      } else {
        a->der = x;
      }
    }
    p->padre = x;
    if (x_es_izq) {
      p->izq = x->der;
      p->n_izq = x->n_der;
      if (p->izq) {
        p->izq->padre = p;
      }
      x->der = p;
      x->n_der = p->n();
    } else {
      p->der = x->izq;
      p->n_der = x->n_izq;
      if (p->der) {
        p->der->padre = p;
      }
      x->izq = p;
      x->n_izq = p->n();
    }
  }
  void splay() {
    aplica_reversa();
    while (!es_raiz()) {
      if (!tiene_abuelo()) {
        rota();
        continue;
      }
      if (es_izq() ^ padre->es_izq()) {
        rota();
        rota();
      } else {
        padre->rota();
        rota();
      }
    }
  }
  void aplica_reversa(bool recursion = true) {
    if (recursion && padre) {
      padre->aplica_reversa();
    }
    if (!reversa) {
      return;
    }
    reversa = false;
    swap(n_izq, n_der);
    swap(izq, der);
    if (izq) {
      izq->reversa = !izq->reversa;
    }
    if (der) {
      der->reversa = !der->reversa;
    }
  }
  arbol *busca(int k) {
    aplica_reversa(false);
    if (n_der == k - 1) {
      return this;
    }
    if (n_der >= k) {
      return der->busca(k);
    }
    return izq->busca(k - n_der - 1);
  }
  arbol *busca_izq() {
    aplica_reversa(false);
    if (izq) {
      return izq->busca_izq();
    }
    return this;
  }
  int posicion() {
    splay();
    return n_izq;
  }
};
arbol *opera(arbol *raiz, int k) {
  arbol *nodo = raiz->busca(k);
  nodo->splay();
  arbol *izq = nodo->izq;
  if (!izq) {
    nodo->reversa = !nodo->reversa;
    return nodo;
  }
  izq->padre = nullptr;
  nodo->izq = nullptr;
  nodo->n_izq = 0;
  izq = izq->busca_izq();
  izq->splay();
  nodo->reversa = !nodo->reversa;
  izq->izq = nodo;
  nodo->padre = izq;
  izq->n_izq = nodo->n();
  return izq;
}
char orden[N];
arbol nodos[N];
int main() {
  int n;
  scanf("%d %s %s", &n, s, t);
  if (!is_permutation(s, s + n, t)) {
    printf("-1\n");
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      orden[i] = t[n - 1 - i / 2];
    } else {
      orden[i] = t[i / 2];
    }
  }
  reverse(orden, orden + n);
  arbol *raiz = nullptr;
  map<char, vector<arbol *>> nodos_char;
  for (int i = 0; i < n; ++i) {
    char c = s[i];
    nodos_char[c].push_back(&nodos[i]);
    nodos[i].c = c;
    nodos[i].n_izq = i;
    nodos[i].n_der = 0;
    nodos[i].padre = nullptr;
    nodos[i].izq = raiz;
    nodos[i].der = nullptr;
    if (raiz) {
      raiz->padre = &nodos[i];
    }
    raiz = &nodos[i];
  }
  vector<int> instrucciones;
  for (int i = 0; i < n; ++i) {
    char c = orden[i];
    arbol *nodo = nodos_char[c].back();
    nodos_char[c].pop_back();
    raiz = nodo;
    int pos = nodo->posicion();
    int l_a = i;
    int l_b = pos - l_a;
    int l_c = n - l_a - l_b - 1;
    vector<int> nuevas_inst = {l_c + 1, l_b, l_a + 1};
    for (int x : nuevas_inst) {
      if (x == 0) {
        continue;
      }
      instrucciones.push_back(x);
      raiz = opera(raiz, x);
    }
  }
  printf("%d\n", (int)instrucciones.size());
  bool primero = true;
  for (int x : instrucciones) {
    if (primero) {
      primero = false;
    } else {
      printf(" ");
    }
    printf("%d", x);
  }
  printf("\n");
}
