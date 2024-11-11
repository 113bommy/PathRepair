#include<bits/stdc++.h>

using namespace std;

using LL = long long;
const int NDigit = 19;

int mod, pw10[NDigit];
int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int mul(int a, int b) { return (int)( (LL)a * b % mod); }

LL nTerm, a, b;

struct Matrix {
    int nR, nC;
    vector<vector<int> > a;
    Matrix(int _nR, int _nC) : nR(_nR), nC(_nC) {
        a.assign(nR, vector<int>(nC, 0) );
    }
    Matrix operator*(const Matrix &_) const {
        Matrix ret(nR, _.nC);
        for (int i = 0; i < ret.nR; ++i) {
            for (int j = 0; j < ret.nC; ++j) {
                for (int k = 0; k < nC; ++k) ret.a[i][j] = add(ret.a[i][j], mul(a[i][k], _.a[k][j]) );
            }
        }
        return ret;
    }
    Matrix binpw(LL exp) const {
        Matrix M = *this;
        assert(nR == nC);
        Matrix ret(nR, nC);
        for (int i = 0; i < nR; ++i) ret.a[i][i] = 1;
        for (; exp; exp >>= 1, M = M * M) if (exp & 1) ret = ret * M;
        return ret;
    }
    void debug() {
        for (int i = 0; i < nR; ++i) {
            for (int j = 0; j < nC; ++j) cerr << a[i][j] << ' '; cerr << '\n';
        }
        cerr << "====\n";
    }
};

int nDigit(LL num) {
    int ret = 0;
    while (num) { ++ret; num /= 10; }
    return ret;
}

int main() {
    scanf(" %lld %lld %lld %d", &nTerm, &a, &b, &mod);

    pw10[0] = 1;
    for (int i = 1; i < NDigit; ++i) pw10[i] = mul(pw10[i - 1], 10);

    Matrix cur(1, 3);
    cur.a[0][0] = (int)(b % mod); cur.a[0][1] = (int)(a % mod); cur.a[0][2] = (int)(a % mod);

    for (LL prv = 0; prv + 1 < nTerm; ) {
        LL lNxt = prv + 1, rNxt = nTerm - 1;
        while (lNxt < rNxt) {
            LL mNxt = (lNxt + rNxt + 1) >> 1;
            if (nDigit(a + b * mNxt) == nDigit(a + (prv + 1) * b) ) lNxt = mNxt;
            else rNxt = mNxt - 1;
        }
        LL nxt = lNxt;

        Matrix tranMatrix(3, 3);
        tranMatrix.a[0][0] = tranMatrix.a[0][1] = tranMatrix.a[0][2] = tranMatrix.a[1][1] = tranMatrix.a[1][2] = 1;
        tranMatrix.a[2][2] = pw10[nDigit(a + nxt * b)];
        tranMatrix = tranMatrix.binpw(nxt - prv);
        cur = cur * tranMatrix;
        prv = nxt;
    }

    printf("%d\n", cur.a[0][2]);

    return 0;
}
