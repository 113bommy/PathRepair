#include <bits/stdc++.h>
using namespace std;

int main() {
    string N;
    bool flag = false;
    while (cin >> N) {
        if (flag) cout << endl;
        flag = true;
        while (N.size() < 5) N = "0" + N;
        vector<string> s(8);
        s[2] = "=====";

        for (int i = 0; i < N.size(); i++) {
            int n = N[i] - '0';
            if (n > 4) {
                s[1] += '*';
                s[0] += ' ';
            } else {
                s[0] += '*';
                s[1] += ' ';
            }

            int p;
            if (n >= 5) p = n - 5;
            else p = n;
            for (int j = 0; j < p; j++) {
                s[3+j] += "*";
            }

            s[3+p] += ' ';

            for (int j = 4+p; j < 8; j++) {
                s[j] += '*';
            }
        }

        for (auto i : s) cout << i << endl;
    }

    return 0;
}