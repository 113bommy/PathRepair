#include <bits/stdc++.h>
using namespace std;
const long long N = 5e4 + 3.5, MOD = 1e9 + 7.5;
int max_value, bit_len;
int n, m;
int an[N];
vector<int> an_bits[N];
struct node {
  int cnt, left, right, parent;
};
node graph[N * 33];
int nnt;
long long two_pow[35];
long long powMod(long long a, long long b) {
  if (b == 0)
    return 1;
  else {
    long long tmp = powMod(a, b / 2);
    if (b % 2 == 0)
      return tmp * tmp % MOD;
    else
      return tmp * tmp % MOD * a % MOD;
  }
}
vector<int> value_2_insert_bit(int value) {
  int tmp = value;
  stack<int> buf;
  vector<int> ret;
  ret.reserve(bit_len);
  while (tmp) {
    int bit = tmp % 2;
    buf.push(bit);
    tmp /= 2;
  }
  for (int i = 0; i < bit_len - buf.size(); i++) {
    ret.push_back(0);
  }
  while (!buf.empty()) {
    int top = buf.top();
    ret.push_back(top);
    buf.pop();
  }
  return ret;
}
void insert(const vector<int> &ele) {
  int cur = 0;
  ++graph[cur].cnt;
  for (int i = 0; i < bit_len; i++) {
    int bit = ele[i];
    if (bit == 0) {
      if (graph[cur].left != -1) {
        cur = graph[cur].left;
      } else {
        nnt++;
        graph[cur].left = nnt - 1;
        graph[nnt].parent = cur;
        cur = nnt - 1;
      }
    } else {
      if (graph[cur].right != -1)
        cur = graph[cur].right;
      else {
        nnt++;
        graph[cur].right = nnt - 1;
        graph[nnt].parent = cur;
        cur = nnt - 1;
      }
    }
    ++graph[cur].cnt;
  }
}
int tmp_buf[30];
vector<pair<int, int> > go_to_result_pair(int snt) {
  vector<pair<int, int> > prev_s;
  prev_s.push_back(pair<int, int>(0, 0));
  int a, b, tmp_a, tmp_b;
  for (int i = 0; i < snt; i++) {
    vector<pair<int, int> > s;
    int bit = tmp_buf[i];
    for (int j = 0; j < prev_s.size(); j++) {
      a = prev_s[j].first, b = prev_s[j].second;
      if (bit == 0) {
        tmp_a = graph[a].left, tmp_b = graph[b].left;
        if (tmp_a != -1 && tmp_b != -1)
          s.push_back(pair<int, int>(tmp_a, tmp_b));
        tmp_a = graph[a].right, tmp_b = graph[b].right;
        if (tmp_a != -1 && tmp_b != -1)
          s.push_back(pair<int, int>(tmp_a, tmp_b));
      } else {
        tmp_a = graph[a].left, tmp_b = graph[b].right;
        if (tmp_a != -1 && tmp_b != -1)
          s.push_back(pair<int, int>(tmp_a, tmp_b));
        if (a != b) {
          tmp_a = graph[a].right, tmp_b = graph[b].left;
          if (tmp_a != -1 && tmp_b != -1)
            s.push_back(pair<int, int>(tmp_a, tmp_b));
        }
      }
    }
    prev_s = std::move(s);
  }
  return prev_s;
}
long long get_less_num(int snt) {
  vector<pair<int, int> > s = go_to_result_pair(snt);
  long long ret = 0;
  for (int i = 0; i < s.size(); i++) {
    int x = s[i].first, y = s[i].second;
    if (x != y)
      ret += (long long)graph[x].cnt * graph[y].cnt;
    else
      ret += (long long)graph[x].cnt * (graph[x].cnt - 1) / 2;
  }
  return ret;
}
int bit_num_left[2][35], bit_num_right[2][35];
void accumulate(int idx, int pos, int buffer[][35]) {
  int left = graph[idx].left, right = graph[idx].right;
  if (left != -1) {
    buffer[0][pos] += graph[left].cnt;
    accumulate(left, pos + 1, buffer);
  }
  if (right != -1) {
    buffer[1][pos] += graph[right].cnt;
    accumulate(right, pos + 1, buffer);
  }
}
long long cal_total_pair_sum(int snt) {
  vector<pair<int, int> > s = go_to_result_pair(snt);
  long long tmp_val = 0, ans = 0;
  for (int i = 0; i < snt; i++) {
    if (tmp_buf[i] == 1) {
      tmp_val = (tmp_val + two_pow[bit_len - i - 1]) % MOD;
    }
  }
  for (int i = 0; i < s.size(); i++) {
    int a = s[i].first, b = s[i].second;
    if (a != b) {
      for (int j = snt; j < bit_len; j++) {
        for (int k = 0; k < 2; k++)
          bit_num_left[k][j] = bit_num_right[k][j] = 0;
      }
      accumulate(a, snt, bit_num_left), accumulate(b, snt, bit_num_right);
      ans = (ans + tmp_val * graph[a].cnt % MOD * graph[b].cnt) % MOD;
      for (int j = snt; j < bit_len; j++) {
        ans = (ans + two_pow[bit_len - j - 1] * bit_num_left[0][j] % MOD *
                         bit_num_right[1][j]) %
              MOD;
        ans = (ans + two_pow[bit_len - j - 1] * bit_num_left[1][j] % MOD *
                         bit_num_right[0][j]) %
              MOD;
      }
    } else {
      for (int j = snt; j < bit_len; j++) {
        for (int k = 0; k < 2; k++) bit_num_left[k][j] = 0;
      }
      accumulate(a, snt, bit_num_left);
      for (int j = snt; j < bit_len; j++) {
        ans = (ans + two_pow[bit_len - j - 1] * bit_num_left[0][j] % MOD *
                         bit_num_left[1][j]) %
              MOD;
      }
    }
  }
  return ans;
}
long long get_m_st_value_and_ans(int m) {
  int V = 0;
  long long last_one_ans = 0;
  for (int i = 0; i < bit_len; i++) {
    tmp_buf[i] = 1;
    int K = get_less_num(i + 1);
    if (V + K < m) {
      V = V + K;
      last_one_ans = (last_one_ans + cal_total_pair_sum(i + 1)) % MOD;
      tmp_buf[i] = 0;
    }
  }
  long long m_val = 0;
  for (int i = 0; i < bit_len; i++) {
    if (tmp_buf[i] == 1) {
      m_val = (m_val + two_pow[bit_len - i - 1]) % MOD;
    }
  }
  last_one_ans = (last_one_ans + m_val * (m - V)) % MOD;
  return last_one_ans;
}
void print(int idx, int deep) {
  int left = graph[idx].left, right = graph[idx].right;
  if (right != -1) print(right, deep + 1);
  for (int i = 0; i < deep; i++) printf(" ");
  printf("idx = %d cnt = %d\n", idx, graph[idx].cnt);
  if (left != -1) print(left, deep + 1);
}
int main() {
  for (int i = 0; i < N * 33; i++)
    graph[i].cnt = 0, graph[i].left = graph[i].right = graph[i].parent = -1;
  for (int i = 0; i < 34; i++) {
    if (i == 0)
      two_pow[i] = 1;
    else
      two_pow[i] = 2 * two_pow[i - 1] % MOD;
  }
  scanf("%d%d", &n, &m);
  max_value = INT_MIN;
  for (int i = 1; i <= n; i++)
    scanf("%d", &an[i]), max_value = max(max_value, an[i]);
  bit_len = 0;
  int tmp = max_value;
  while (tmp) {
    bit_len += 1;
    tmp /= 2;
  }
  for (int i = 1; i <= n; i++) an_bits[i] = value_2_insert_bit(an[i]);
  nnt = 1;
  for (int i = 1; i <= n; i++) insert(an_bits[i]);
  long long ans = get_m_st_value_and_ans(m);
  printf("%lld\n", ans);
  return 0;
}
