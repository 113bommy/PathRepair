#include<iostream>
using namespace std;
int pre[100000], in[100000], post[100000], n, pos, cnt;
void rec(int l, int r) { if (l >= r) { return; }int root = pre[pos++]; int m = 0; for (int i = 0; i < n; i++) { if (in[i] == root) { m = i; } }rec(l, m); rec(m + 1, r); post[cnt] = root; cnt++; }
int main() { cin >> n; for (int i = 0; i < n; i++) { cin >> pre[i]; }for (int i = 0; i < n; i++) { cin >> in[i]; }rec(0, n); for (int i = 0; i < n; i++) { if (i) { cout << ' '; }cout << post[i]; }cout << endl; return 0; }