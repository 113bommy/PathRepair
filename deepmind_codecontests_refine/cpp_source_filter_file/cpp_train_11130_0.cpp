#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define dump(x) cerr<<#x<<" = "<<(x)<<endl;

int pow10[10] = {1};

void gen()
{
    repi(i,1,10)
        pow10[i] = pow10[i - 1] * 10;
}

int N, M;
vector<bool> nonzero;
vector<int> coef;

int ans, used;

void init()
{
    nonzero.clear();
    coef.clear();
    ans = used = 0;
}

void input()
{
    map<char,bool> nz;
    map<char,int> c;
    rep(i,N) {
        string s; cin >> s;
        if (s.length() >= 2)
            nz[s[0]] = true;
        rep(j,(int)s.length())
            if (i < N - 1)
                c[s[j]] += pow10[(int) s.length() - j - 1];
            else
                c[s[j]] -= pow10[(int) s.length() - j - 1];
    }
    repit(it,c) {
        nonzero.pb(nz[it->first]);
        coef.pb(it->second);
    }
    M = coef.size();
}

void dfs(int depth, int value)
{
    if (depth == M) {
        ans += value == 0;
        return;
    }
    if (!nonzero[depth] && ~used & 1) {
        used ^= 1;
        dfs(depth + 1, value);
        used ^= 1;
    }
    repi(i,1,10) {
        if (~used >> i & 1) {
            used ^= 1 << i;
            dfs(depth + 1, value + coef[depth] * i);
            used ^= 1 << i;
        }
    }
}

int main()
{
    gen();

    while (cin >> N && N) {
        init();
        input();
        dfs(0, 0);

        cout << ans << endl;
    }
    
    return 0;
}