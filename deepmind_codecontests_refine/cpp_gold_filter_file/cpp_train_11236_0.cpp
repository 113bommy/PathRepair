#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
    vector<int> p, r, a;
    int find(int i) {
        return i == p[i] ? i : (p[i] = find(p[i]));
    }
public:
    UnionFind(int n) : p(n), r(n), a(n, 1) {
        for (int i = 0; i < n; ++i)
            p[i] = i;
    }
    bool same(int i, int j) {
        return find(i) == find(j);
    }
    void unite(int i, int j) {
        i = find(i);
        j = find(j);
        if (r[i] < r[j]) {
            p[i] = j;
        } else {
            p[j] = i;
            r[i] += i != j && r[i] == r[j];
        }
        if (i != j)
            a[p[i]] = a[i] + a[j];
    }
    int number(int i) {
        return a[find(i)];
    }
};

int main() {
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> a(n - 1);
    for (auto& p : a)
        cin >> p.second.first >> p.second.second >> p.first;
    sort(a.begin(), a.end());
    UnionFind uf(n);
    long long sm = 0;
    for (auto& p : a) {
        auto& q = p.second;
        sm += (long long)p.first * uf.number(q.first) * uf.number(q.second);
        uf.unite(q.first, q.second);
    }
    cout << sm << endl;
    return 0;
}