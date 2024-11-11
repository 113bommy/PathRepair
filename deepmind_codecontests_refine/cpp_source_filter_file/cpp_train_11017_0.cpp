#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ma = 0, mi = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > a[ma])ma = i;
        if (a[i] < a[mi])mi = i;
    }

    vector<vector<int>> ope;
    if (a[ma] * 2 + a[0] > -(a[mi] * 2 + a[n - 1]) {
        ope.push_back({ma, 0});
        for (int i = 1; i < n; i++) ope.push_back({i - 1, i});
    } else {
        ope.push_back({mi, n - 1});
        for (int i = n - 1; i > 0; i--) ope.push_back({i, i - 1});
    }

    cout << ope.size() * 2 << endl;
    for (auto x:ope) {
        cout << x[0] + 1 << " " << x[1] + 1 << endl;
        cout << x[0] + 1 << " " << x[1] + 1 << endl;
    }
    return 0;
}