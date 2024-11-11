#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(3, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> v[j][i];
    for (int i = 0; i < n; i++) {
        int ans = 0;
        for (int j = 0; j < 3; j++) {
            if (count(v[j].begin(), v[j].end(), v[j][i]) == 1)
                ans += v[j][i];
        }
        cout << ans << endl;
    }
}
