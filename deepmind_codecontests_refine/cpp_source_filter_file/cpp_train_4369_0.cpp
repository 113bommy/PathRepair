g#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_H 100
#define MAX_W 100

#define INF (1<<28)

bool isdigit(string s) {
    for (int i = 0; i < s.size(); i++) 
        if (!isdigit(s[i]))
            return false;
    return true;
}

int to_i(string s) {
    istringstream is(s);
    int n; is >> n;
    return n;
}

int w, h;
string F[MAX_H][MAX_W];
int sy, sx;
int gy, gx;

struct P {
    int y, x;
    int t;
    P(int y=0, int x=0) : y(y), x(x) { t = INF; }
};

int dist(const P &a, const P &b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

vector<P> graph[50*50+1];
int main() {
    while (cin >> w >> h, w || h) {
        for (int i = 0; i <= 50*50; i++) graph[i].clear();
        for (int i = 0; i < h; i++) 
            for (int j = 0; j < w; j++) 
                cin >> F[i][j];
        int n = 0;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++) {
                if (isdigit(F[i][j])) {
                    graph[to_i(F[i][j])].push_back(P(i, j));
                    n = max(n, to_i(F[i][j]));
                }
                if (F[i][j] == "S") sy = i, sx = j;
                if (F[i][j] == "G") gy = i, gx = j;
            }
        graph[0].push_back(P(sy, sx)); graph[0][0].t = 0;
        graph[n+1].push_back(P(gy, gx));
        for (int i = 1; i <= n+1; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                for (int k = 0; k < graph[i-1].size(); k++) {
                    graph[i][j].t = min(graph[i][j].t, graph[i-1][k].t + dist(graph[i-1][k], graph[i][j]));
                }
            }
        }
        //for (int i = 1; i <= n+1; i++) {
        //    cout << "i = " << i << endl;
        //    for (int j = 0; j < graph[i].size(); j++) {
        //        cout << graph[i][j].t << ' ';
        //    }
        //    cout << endl;
        //}
        cout << graph[n+1][0].t << endl;
    }
    return 0;
}