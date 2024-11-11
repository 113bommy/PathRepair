#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int N = 100005;

int n, m;
int a[N];
int bit[N];
int it[4 * N];
int lz[4 * N];
vector<int> val;
vector<int> v[N];
vector<int> start;
vector<int> finish;

void upd(int x) {
    for (int i = x; i > 0; i -= i & -i) bit[i]++;
}

int get(int x) {
    int ans = 0;
    for (int i = x; i <= n; i += i & -i) ans += bit[i];
    return ans;
}

void lazy(int node, int l, int r) {
    if (!lz[node]) return;
    it[node] += lz[node];
    if (l != r) {
        lz[node << 1] += lz[node];
        lz[node << 1 | 1] += lz[node];
    }
    lz[node] = 0;
}

void upd(int node, int l, int r, int ll, int rr, int v, bool t) {
    lazy(node, l, r);
    if (l > r || ll > r || l > rr || ll > rr) return;
    if (ll <= l && r <= rr) {
        if (!t) lz[node] = v; else lz[node] = -v;
        lazy(node, l, r); return;
    }
    int mid = (l + r) >> 1;
    upd(node << 1, l, mid, ll, rr, v, t);
    upd(node << 1 | 1, mid + 1, r, ll, rr, v, t);
    it[node] = max(it[node << 1], it[node << 1 | 1]);
}

void upd(int x, int y, int z, int t) {
    int l = 0, r = m;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (a[finish[mid]] <= x) l = mid;
        else r = mid - 1;
    }
    if (finish[l] < y) return;
    int tmp = l;
    l = 0, r = tmp;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (finish[mid] >= y) r = mid;
        else l = mid + 1;
    }
    if (a[finish[tmp]] == x) {
        upd(1, 0, m, tmp, tmp, z - 1, t), tmp--;
    }
    upd(1, 0, m, l, tmp, z, t);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; val.push_back(a[i]);
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    for (int i = 1; i <= n; ++i) {
        a[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin() + 1;
        v[a[i]].push_back(i);
    }
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        res += get(a[i]); upd(a[i] - 1);
    }
    if (!res) {
        for (int i = 1; i <= n; ++i) {
            if (a[i] == a[i - 1]) {
                cout << "0\n"; return 0;
            }
        }
        cout << "1\n"; return 0;
    }
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > cur) {
            cur = a[i]; start.push_back(i);
        }
    }
    cur = 1e9;
    for (int i = n; i >= 1; --i) {
        if (a[i] < cur) {
            cur = a[i]; finish.push_back(i);
        }
    }
    reverse(finish.begin(), finish.end());
    m = finish.size() - 1;
    int mx = 0;
    for (int i = 0; i < start.size(); ++i) {
        int st = 1;
        if (i) {
            st = a[start[i - 1]];
            for (int j = start[i - 1]; j < start[i]; ++j) {
                if (a[j] == a[start[i - 1]]) continue;
                upd(a[j], j, 2, 1);
            }
        }
        for (int j = st; j <= a[start[i]]; ++j) {
            for (auto k : v[j]) {
                if (k <= start[i]) continue;
                if (j == a[start[i]]) upd(j, k, 1, 0);
                else upd(j, k, 2, 0);
            }
        }
        mx = max(mx, it[1]);
        for (auto j : v[a[start[i]]]) {
            if (j == start[i]) continue;
            upd(a[start[i]], j, 1, 1);
        }
    }
    cout << res - mx << '\n';
}