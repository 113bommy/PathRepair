#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    map<char, int> mp;
    for (char c : s) {
        mp[c]++;
    }
    cout << all_of(mp.begin(), mp.end(), [](pair<char, int> p){ return p.second % 2 == 0; }) ? "Yes" : "No" << endl;
}