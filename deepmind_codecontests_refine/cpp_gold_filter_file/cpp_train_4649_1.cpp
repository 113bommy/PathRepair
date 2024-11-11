#include <bits/stdc++.h>
using namespace std;
int n, i, pos;
long long p[300011], s[300011];
pair<long long, long long> dp[300011];
pair<long long, long long> from_here[300011], until_here[300011];
vector<int> moves;
void upd(pair<long long, long long>& a, pair<long long, long long> b) {
  a = min(a, b);
}
long long execute(long long& a, long long& b) {
  long long aux = min(a, b);
  a -= aux;
  b -= aux;
  return 2LL * aux;
}
long long magic3(long long a, long long b, long long c) {
  long long ans = 0;
  ans += execute(b, c);
  ans += 2 * b + c;
  return ans;
}
pair<long long, long long> get_from_here(int pos) {
  return make_pair(
      dp[pos].first + magic3(p[pos], p[pos + 1], p[pos + 2]) - s[pos + 2], pos);
}
long long case_one(long long a, long long b, long long c) {
  long long ans = 0;
  ans += 2LL * b;
  return ans;
}
long long case_two(long long a, long long b, long long c, long long d) {
  long long ans = 0;
  ans += execute(b, c);
  ans += 2LL * (b + c);
  return ans;
}
long long case_three_one(long long a, long long b, long long c, long long d,
                         long long e) {
  long long ans = 0;
  ans += execute(b, c);
  ans += execute(c, d);
  ans += 2LL * (b + d);
  return ans;
}
long long case_three_two(long long a, long long b, long long c, long long d,
                         long long e) {
  long long ans = 0;
  ans += execute(c, d);
  ans += execute(b, c);
  ans += 2LL * (b + d);
  return ans;
}
long long case_three(long long a, long long b, long long c, long long d,
                     long long e) {
  return min(case_three_one(a, b, c, d, e), case_three_two(a, b, c, d, e));
}
void get_moves(int l, int r) {
  int i, j;
  if (l + 1 >= r) return;
  if (r - l - 1 == 3) {
    if (case_three_two(p[l], p[l + 1], p[l + 2], p[l + 3], p[l + 4]) <
        case_three_one(p[l], p[l + 1], p[l + 2], p[l + 3], p[l + 4])) {
      if (p[l + 2] > 0 && p[l + 3] > 0) {
        execute(p[l + 2], p[l + 3]);
        moves.push_back(l + 2);
      }
    }
  }
  i = l + 1;
  j = r - 1;
  while (i < j) {
    if (p[i] > 0 && p[i + 1] > 0) {
      execute(p[i], p[i + 1]);
      moves.push_back(i);
    }
    if (p[j] > 0 && p[j - 1] > 0) {
      execute(p[j], p[j - 1]);
      moves.push_back(j - 1);
    }
    i++;
    j--;
  }
  if (p[l] > 0 && p[l + 1] > 0) {
    execute(p[l], p[l + 1]);
    moves.push_back(l);
  }
  if (p[r] > 0 && p[r - 1] > 0) {
    execute(p[r - 1], p[r]);
    moves.push_back(r - 1);
  }
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%lld", &p[i]);
    s[i] = s[i - 1] + p[i];
  }
  dp[0] = make_pair(0, 0);
  from_here[0] = until_here[0] = get_from_here(0);
  dp[1] = make_pair(0, 0);
  from_here[1] = get_from_here(1);
  until_here[1] = min(until_here[0], from_here[1]);
  for (i = 2; i <= n + 1; i++) {
    dp[i] =
        make_pair(dp[i - 2].first + case_one(p[i - 2], p[i - 1], p[i]), i - 2);
    if (i - 3 >= 0) {
      upd(dp[i], make_pair(dp[i - 3].first +
                               case_two(p[i - 3], p[i - 2], p[i - 1], p[i]),
                           i - 3));
    }
    if (i - 4 >= 0) {
      upd(dp[i],
          make_pair(dp[i - 4].first + case_three(p[i - 4], p[i - 3], p[i - 2],
                                                 p[i - 1], p[i]),
                    i - 4));
    }
    if (i - 5 >= 0) {
      upd(dp[i], make_pair(until_here[i - 5].first + s[i - 3] +
                               magic3(p[i], p[i - 1], p[i - 2]),
                           until_here[i - 5].second));
    }
    from_here[i] = get_from_here(i);
    until_here[i] = min(until_here[i - 1], from_here[i]);
  }
  pair<long long, long long> best;
  best = min(make_pair(dp[n].first, n), make_pair(dp[n + 1].first, n + 1));
  pos = best.second;
  vector<int> sol = {};
  while (pos != 0) {
    sol.push_back(pos);
    pos = dp[pos].second;
  }
  sol.push_back(0);
  reverse(sol.begin(), sol.end());
  for (i = 0; i + 1 < sol.size(); i++) get_moves(sol[i], sol[i + 1]);
  printf("%d\n", moves.size());
  for (auto e : moves) printf("%d\n", e);
  cerr << "\n\n Total cost " << best.first << ' ' << best.first / 2 << '\n';
  return 0;
}
