#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

map<string, vector<string>> word;
set<int> size;

string button(const string& str) {
    string result = "";
    for(const auto& c: str) {
        if('a' <= c && c <= 'o') result += (c - 'a') / 3 + '2';
        if('p' <= c && c <= 's') result += '7';
        if('t' <= c && c <= 'v') result += '8';
        if('w' <= c && c <= 'z') result += '9';
    }
    return result;
}

void dfs(string str, vector<string>& list) {
    if(str.empty()) {
        for(int i = 0; i < list.size(); ++i) cout << (i ? " " : "") << list[i];
        cout << "." << endl;
    }

    for(const auto& s: size) {
        if(str.size() < s) break;
        if(!word.count(str.substr(0, s))) continue;
        for(const auto& w: word[str.substr(0, s)]) {
            list.push_back(w);
            dfs(str.substr(s), list);
            list.pop_back();
        }
    }
}

int main() {
    int n;
    while(cin >> n, n) {
        word.clear();
        size.clear();
        for(int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            word[button(s)].push_back(s);
            size.insert(s.size());
        }
        vector<string> list;
        string str;
        cin >> str;
        dfs(str, list);
        cout << "--" << endl;
    }
}