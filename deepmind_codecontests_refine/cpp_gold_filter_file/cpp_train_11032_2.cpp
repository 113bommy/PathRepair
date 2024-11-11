#include <bits/stdc++.h>
using namespace std;int main(){int N;cin >> N;map<pair<int, int>, int> mp;for (int i = 0, y, x, w; i < N; i++) cin >> y >> x >> w, mp[{y, x}] += w, mp[{y - 1, x}] += w, mp[{y, x - 1}] += w, mp[{y - 1, x - 1}] += w;int ans = 0;for (const auto& p : mp) ans = max(ans, p.second);cout << ans << " / " << 1 << endl;return 0;}
