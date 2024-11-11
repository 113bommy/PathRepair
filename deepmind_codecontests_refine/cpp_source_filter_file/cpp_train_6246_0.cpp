include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using vi = vector<i64>;
using vvi = vector<vi>;

// 二部グラフの最大重みマッチング
class Hungarian {
    int n, p, q;
    vvi mat;
    vi fx, fy, x, y;
    const i64 INF = 1e9;

public:
    Hungarian(const vvi& mat) : mat(mat) {
        n = mat.size();
        fx.assign(n, INF);
        fy.assign(n, 0);
        x.assign(n, -1);
        y.assign(n, -1);
    }

    i64 run() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                fx[i] = max(fx[i], mat[i][j]);
            }
        }

        for (int i = 0; i < n;) {
            vi t(n, -1), s(n + 1, i);
            for (p = q = 0; p <= q && x[i] < 0; p++) {
                for (int k = s[p], j = 0; j < n && x[i] < 0; j++) {
                    if (fx[k] + fy[j] == mat[k][j] && t[j] < 0) {
                        s[++q] = y[j];
                        t[j] = k;
                        if (s[q] < 0) {
                            for (p = j; p >= 0; j = p) {
                                y[j] = k = t[j];
                                p = x[k];
                                x[k] = j;
                            }
                        }
                    }
                }
            }
            if (x[i] < 0) {
                i64 d = INF;
                for (int k = 0; k <= q; k++) {
                    for (int j = 0; j < n; j++) {
                        if (t[j] < 0) {
                            d = min(d, fx[s[k]] + fy[j] - mat[s[k]][j]);
                        }
                    }
                }
                for (int j = 0; j < n; j++) {
                    fy[j] += (t[j] < 0 ? 0 : d);
                }
                for (int k = 0; k <= q; k++) {
                    fx[s[k]] -= d;
                }
            } else {
                i++;
            }
        }
        i64 ret = 0;
        for (int i = 0; i < n; i++) {
            ret += mat[i][x[i]];
        }
        return ret;
    }

    int match_y(int k) {
        return x[k];
    }

    int match_x(int k) {
        return y[k];
    }
};

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        long long sum = 0;
        vector<vector<int>> as(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                int a;
                cin >> a;
                as[i].push_back(a);
            }
            sum += as[i][0] * as[i][1] * as[i][2];
            sort(as[i].begin(), as[i].end());
        }
        vvi mat(n, vi(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bool ok = true;
                for (int k = 0; k < 3; k++) {
                    if (as[i][k] >= as[j][k]) ok = false;
                }
                if (ok) {
                    mat[i][j] = as[i][0] * as[i][1] * as[i][2];
                }
            }
        }
        Hungarian h(mat);
        cout << sum - h.run() << endl;
    }
}
