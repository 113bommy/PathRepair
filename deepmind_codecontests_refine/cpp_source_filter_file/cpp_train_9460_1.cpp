#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

map<string,set<int>> p;

int main()
{
    string str;
    int t;
    while (cin >> str >> t) p[str].insert(t);
    for (auto it = p.begin(); it != p.end(); it++) {
        auto s = it->second.bigen();
        cout << it->first  << endl << *s;
        for (++s; s != it->second.end(); s++)
            cout << " " << *s;
        cout << endl;
    }

    return 0;
}