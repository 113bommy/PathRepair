#include <cstdio>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

template <size_t T>
bool prevSubset(bitset<T>& bs, const bitset<T>& mask)
{
    bs = bs.to_ulong() - 1ull;
    bs &= mask;
    if(bs.none())
        return false;
    return true;
}

int n, m;
vector<vector<int> > r;

vector<vector<vector<int> > > memo;

int solve(int d, int win, bitset<16> rest)
{
    if(rest.count() == 1)
        return 1;
    if(d == -1)
        return 0;

    if(memo[d][win][rest.to_ulong()] != -1)
        return memo[d][win][rest.to_ulong()];

    int ret = 0;
    bitset<16> bs1 = rest;
    while(prevSubset(bs1, rest)){
        bitset<16> bs2 = rest ^ bs1;
        if(bs1.count() > (1<<d) || bs2.count() > (1<<d))
            continue;
        if(!bs1[win])
            continue;

        for(int i=0; i<n; ++i){
            if(bs2[i] && r[win][i] == 1)
                ret += solve(d-1, win, bs1) * solve(d-1, i, bs2);
        }
    }

    return memo[d][win][rest.to_ulong()] = ret;
}

int main()
{
    for(;;){
        cin >> n >> m;
        if(n == 0)
            return 0;

        r.assign(n, vector<int>(n));
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                cin >> r[i][j];
            }
        }

        int d = 1;
        while((1 << d) < n)
            ++ d;

        memo.assign(d, vector<vector<int> >(n, vector<int>(1<<n, -1)));
        cout << solve(d-1, m-1, (1<<n)-1) << endl;
    }
}