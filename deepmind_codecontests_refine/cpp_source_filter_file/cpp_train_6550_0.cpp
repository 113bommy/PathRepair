#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
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
#include <functional>
using namespace std;

vector<int> len;
vector<map<int, int> > value;

int dfs(string& s, int& k)
{
    if(isdigit(s[k])){
        int ret = 0;
        while(k < s.size() && isdigit(s[k])){
            ret *= 10;
            ret += s[k] - '0';
            ++ k;
        }
        return ret;
    }

    char c = s[k];
    k += 2;
    int a = dfs(s, k);
    ++ k;

    if(a == -1 || value[c].find(a) == value[c].end())
        return -1;
    else
        return value[c][a];
}

bool substitute (string& s)
{
    char a=s[0];
    int eq=s.find('='),idx=0;
    int i=dfs(s.substr(2,eq-3),idx);
    if(i==-1 || len[a]<=i) return false;
 
    idx=0;
    int res=dfs(s.substr(eq+1),idx);
    if(res == -1)
        return false;
    value[a][i]=res;
    return true;
}

int solve(vector<string>& s)
{
    len.assign(128, 0);
    value.assign(128, map<int, int>());

    int n = s.size();
    for(int i=0; i<n; ++i){
        if(s[i].find('=') == string::npos){
            int k = 2;
            len[s[i][0]] = dfs(s[i], k);
        }else{
            if(!substitute(s[i]))
                return i + 1;
        }
    }

    return 0;
}

int main()
{
    for(;;){
        vector<string> s;
        for(;;){
            string t;
            cin >> t;
            if(t == ".")
                break;
            s.push_back(t);
        }

        if(s.empty())
            return 0;

        cout << solve(s) << endl;
    }
}