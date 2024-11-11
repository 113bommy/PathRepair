#include <bits/stdc++.h>

using namespace std;

int main()
{
int n, h; cin >> n >> h;
vector<int> a(n), b(n); 
for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
sort(begin(a), end(a));
sort(begin(b), end(b));
int c = 0;
while (H > 0) H -= max(a[n-1], c>n-1 ? 0 : b[n-1-c]), c++;
cout << c << endl;
}