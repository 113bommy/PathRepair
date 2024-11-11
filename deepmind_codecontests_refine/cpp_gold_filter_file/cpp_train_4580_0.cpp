#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
//#define EACH(i, c) for (auto &(i): c)
#define all(c) begin(c),end(c)
//#define EXIST(s, e) ((s).find(e)!=(s).end())
//#define SORT(c) sort(begin(c),end(c))
//#define pb emplace_back
//#define MP make_pair
//#define SZ(a) int((a).size())

//#define LOCAL 0
//#ifdef LOCAL
//#define DEBUG(s) cout << (s) << endl
//#define dump(x)  cerr << #x << " = " << (x) << endl
//#define BR cout << endl;
//#else
//#define DEBUG(s) do{}while(0)
//#define dump(x) do{}while(0)
//#define BR
//#endif


//改造
typedef long long int ll;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //デバッグする時1にしてね
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007
//ここから編集する
vector<ll> a, b;
int dp[2][52][52][52][52][5][2];
int used[2][52][52][52][52][5][2];
int n, m;


ll calc(int my_s, int my_e, int en_s, int en_e) {
    ll ret = 0;
    for (int i = my_s; i < my_e; i++) {
        if (a[i] > 0)ret += a[i];
    }
    for (int i = en_s; i < en_e; i++) {
        if (b[i] > 0)ret -= b[i];
    }
    return ret;
}


ll dfs(int player, int my_s, int my_e, int en_s, int en_e, int pass, int rest) {
    if (used[player][my_s][my_e][en_s][en_e][pass][rest]) {
        return dp[player][my_s][my_e][en_s][en_e][pass][rest];
    }
    used[player][my_s][my_e][en_s][en_e][pass][rest] = true;
    if (player == 0) {
        if (my_e == n) {
            if (rest == 0) {
                //場に出ていない
                if (pass >= 1) {
                    ll pass_score = calc(my_s, my_e, en_s, en_e);
                    return dp[player][my_s][my_e][en_s][en_e][pass][rest] = pass_score;
                } else {
                    int next_pass = pass;
                    next_pass++;//rest == 0
                    ll pass_score = calc(my_s, my_e, en_s, en_e) + dfs(1, my_e, my_e, en_e, en_e, next_pass, rest);
                    return dp[player][my_s][my_e][en_s][en_e][pass][rest] = pass_score;
                }
            } else {
                int next_pass = 0;
                ll pass_score = calc(my_s, my_e, en_s, en_e) + dfs(1, my_e, my_e, en_e, en_e, next_pass, 0);
                return dp[player][my_s][my_e][en_s][en_e][pass][rest] = pass_score;
            }
        }
        if (pass >= 1) {
            ll pass_score = calc(my_s, my_e, en_s, en_e);
            int next_en_s = (a[my_e] != -1) ? en_s : en_e;
            ll put_score = dfs(1, my_s, my_e + 1, next_en_s, en_e, 0, 1);
            ll ret = max(pass_score, put_score);
            return dp[player][my_s][my_e][en_s][en_e][pass][rest] = ret;
        }
        int next_pass = pass;
        if (rest == 0) next_pass++;
        ll pass_score = calc(my_s, my_e, en_s, en_e) + dfs(1, my_e, my_e, en_e, en_e, next_pass, 0);
        int next_en_s = (a[my_e] != -1) ? en_s : en_e;
        ll put_score = dfs(1, my_s, my_e + 1, next_en_s, en_e, 0, 1);
        ll ret = max(pass_score, put_score);

        return dp[player][my_s][my_e][en_s][en_e][pass][rest] = ret;
    } else {
        if (en_e == m) {
            if (rest == 0) {
                //場に出ていない
                if (pass >= 1) {
                    ll pass_score = calc(my_s, my_e, en_s, en_e);
                    return dp[player][my_s][my_e][en_s][en_e][pass][rest] = pass_score;
                } else {
                    int next_pass = pass;
                    next_pass++;
                    ll pass_score = calc(my_s, my_e, en_s, en_e) + dfs(0, my_e, my_e, en_e, en_e, next_pass, 0);
                    return dp[player][my_s][my_e][en_s][en_e][pass][rest] = pass_score;
                }
            } else {
                int next_pass = 0;
                ll pass_score = calc(my_s, my_e, en_s, en_e) + dfs(0, my_e, my_e, en_e, en_e, next_pass, 0);
                return dp[player][my_s][my_e][en_s][en_e][pass][rest] = pass_score;
            }
        }
        if (pass >= 1) {
            ll pass_score = calc(my_s, my_e, en_s, en_e);
            int next_my_s = (b[en_e] != -1) ? my_s : my_e;
            ll put_score = dfs(0, next_my_s, my_e, en_s, en_e + 1, 0, 1);
            ll ret = min(pass_score, put_score);
            return dp[player][my_s][my_e][en_s][en_e][pass][rest] = ret;
        }
        int next_pass = pass;
        if (rest == 0) next_pass++;
        ll pass_score = calc(my_s, my_e, en_s, en_e) + dfs(0, my_e, my_e, en_e, en_e, next_pass, 0);
        int next_my_s = (b[en_e] != -1) ? my_s : my_e;
        ll put_score = dfs(0, next_my_s, my_e, en_s, en_e + 1, 0, 1);
        ll ret = min(pass_score, put_score);

        return dp[player][my_s][my_e][en_s][en_e][pass][rest] = ret;
    }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];

    cout << dfs(0, 0, 0, 0, 0, 0, 0) << endl;

    return 0;
}

