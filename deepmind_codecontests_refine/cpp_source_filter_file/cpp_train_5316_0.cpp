#include <bits/stdc++.h>
#define int long long
using namespace std;

int size;
vector<int> val;
vector<int> lazy;
vector<int> width;

void lazy_propagate(int p) {
    if (lazy[p] > 0) {
        val[p] += lazy[p] * width[p];
        if (p < size-1) {
            lazy[p*2+1] += lazy[p];
            lazy[p*2+2] += lazy[p];
        }
        lazy[p] = 0;
    }
}

void add(int wishl, int wishr, int watchl, int watchr, int k, int x) {
    if (wishr <= watchl || watchr <= wishl) {
        lazy_propagate(k);
        return;
    }
    if (wishl <= watchl && watchr <= wishr) {
        lazy[k] += x;
        lazy_propagate(k);
        return;
    }
    int mid = (watchl+watchr)/2;
    lazy_propagate(k);
    add(wishl, wishr, watchl, mid, k*2+1, x);
    add(wishl, wishr, mid, watchr, k*2+2, x);
    val[k] = val[k*2+1] + val[k*2+2];
}
void add(int wishl, int wishr, int x) {
    add(wishl, wishr, 0, size, 0, x);
}

int getsum(int wishl, int wishr, int watchl, int watchr, int k) {
    if (wishr <= watchl || watchr <= wishl) {
        return 0;
    }
    if (wishl <= watchl && watchr <= wishr) {
        lazy_propagate(k);
        return val[k];
    }
    int mid = (watchl+watchr)/2;
    lazy_propagate(k);
    int sl = getsum(wishl, wishr, watchl, mid, k*2+1);
    int sr = getsum(wishl, wishr, mid, watchr, k*2+2);
    return sl + sr;
}
int getsum(int wishl, int wishr) {
    return getsum(wishl, wishr, 0, size, 0);
}

int main() {
    int n, q;
    cin >> n >> q;
    size = 1;
    while (size < n) size <<= 1;
    val = vector<int>(size*2, 0);
    lazy = vector<int>(size*2, 0);
    width = vector<int>(size*2, 1);

    for (int i = size-2; i >= 0; i--) {
        width[i] = width[i*2+1] + width[i*2+2];
    }

    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        if(type == 0) {
            int x;
            cin >> x;
            add(l-1, r, x);
        } else {
            cout << getsum(l-1, r) << endl;
        }
    }
    return 0;
}