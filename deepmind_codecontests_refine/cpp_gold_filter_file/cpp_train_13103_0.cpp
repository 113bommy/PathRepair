#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

string str;

bool c (map<char,int> m) {
    for (auto i = m.begin(); i !=  m.end(); i++) {
        if (i->second != 0) return false;
    }
    return true;
}

bool dfs(map<char,int> m) {
    if (c(m)) return true;
    for (char i = '1'; i <= '9'; i++) {
        if (m[i] >= 3) {
            m[i] -= 3;
            if (dfs (m)) return true;;
            m[i] += 3;
        }
        if (i + 2 <= '9' && m[i] > 0 && m[i+1] > 0 &&  m[i+2] > 0) {
            m[i]--; m[i + 1]--; m[i + 2]--;
            if (dfs(m)) return true;
            m[i]++; m[i + 1]++; m[i + 2]++;
        }
    }
    return false;
}

int main ()
{
    while (cin >> str) {
        map<char,int> m;
        for (char i = '1' ; i <= '9'; i++) m[i] = 0;
        for (int i = 0; i < str.size(); i++) {
            m[str[i]]++;
        }

        vector<char> res;
        for (char i = '1'; i <= '9'; i++) {
            if (m[i] >= 4) continue;
            m[i]++;
            for (char j = '1'; j <= '9'; j++) {
                if (m[j] >= 2) {
                    m[j] -= 2;
                    if (dfs(m)) {
                        res.push_back(i);
                        m[j] += 2;
                        break;
                    }
                    m[j] += 2;
                }
            }
            m[i]--;
        }
        if (res.size()) {
            cout << res[0];
            for (int i = 1; i < res.size(); i++) cout << " " << res[i];
        } else cout << 0;
        cout << endl;
    }

    return 0;
}