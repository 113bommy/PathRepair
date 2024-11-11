#include <iostream>
#include <vector>
using namespace std;
 
struct st {int from, to;};
vector<st> v;

int main() {
    int m, n, a, b;
    cin >> m >> n;
 
    int c[21];
	fill(c, c+21, 0);
    for (int i = 0;i < n;i++) {
        cin >> a >> b;
        v.push_back((st){a, b});
        c[b]++;
    }
 
    for (int i = 0;i < m;i++) {
        for (int j = 1;j <= m;j++) {
            if (c[j] == 0) {
                cout << j << endl;
            	c[j] = (1 << 10);
                for (int k = 0;k < n;k++) {
                    c[v[k].to] -= (v[k].from == j);
                }
                break;
            }
        }
    }
    return 0;
}