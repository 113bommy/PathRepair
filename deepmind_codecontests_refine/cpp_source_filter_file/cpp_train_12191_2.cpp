#include <bits/stdc++.h>
using namespace std;
struct block {
  vector<int> first;
  int second;
};
block different_blocks[1000];
int no_of_different_blocks = 0;
int no_of_different_divisors = 0;
bool v[1000009];
long long primes[1000009];
int n_primes;
int tmp[1000];
void pre_process();
int sieve();
int fn(int current, long long with_me, int beforeCnt);
int make_array_of_different_divisors();
int get_number_index_in_block_array(int x);
const int inf = 99999999;
int blocks_divisors_array[1000][1000];
vector<int> numPF(long long x);
map<int, int> different_divisors;
int solve(int x, int y);
int get_block_differences(vector<int> x, vector<int> y);
int p = 0;
int main() {
  pre_process();
  int tc;
  scanf("%d", &tc);
  for (int i = 0; i < tc; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", solve(x, y));
  }
  return 0;
}
int solve(int x, int y) {
  int x_index = get_number_index_in_block_array(x);
  int y_index = get_number_index_in_block_array(y);
  if (p) {
    printf(" index %d %d\n", x_index, y_index);
    printf(" the deiv %d %d\n", different_blocks[x_index].second,
           different_blocks[y_index].second);
  }
  int ret = inf;
  for (map<int, int>::iterator it = different_divisors.begin();
       it != different_divisors.end(); it++) {
    pair<int, int> x = *it;
    int div_index = x.second;
    if (p) {
      printf("=========== %d %d %d   the index %d\n", x.first,
             blocks_divisors_array[x_index][div_index],
             blocks_divisors_array[y_index][div_index], div_index);
    }
    if (p) {
    }
    ret = min(ret, blocks_divisors_array[x_index][div_index] +
                       blocks_divisors_array[y_index][div_index]);
  }
  return ret;
}
void pre_process() {
  n_primes = sieve();
  no_of_different_blocks = fn(0, 1, 70);
  no_of_different_divisors = make_array_of_different_divisors();
  block x;
  int div = 1;
  x.first.push_back(0);
  sort(x.first.begin(), x.first.end());
  x.second = div;
  different_blocks[no_of_different_blocks++] = x;
  for (int i = 0; i < no_of_different_blocks; i++)
    for (int j = 0; j < no_of_different_divisors; j++)
      blocks_divisors_array[i][j] = inf;
  for (int i = 0; i < no_of_different_blocks; i++) {
    for (int j = 0; j < no_of_different_blocks; j++) {
      {
        int x = get_block_differences(different_blocks[i].first,
                                      different_blocks[j].first);
        int div = different_blocks[j].second;
        int indx = different_divisors[div];
        blocks_divisors_array[i][indx] = min(blocks_divisors_array[i][indx], x);
        if (p) {
          if (div == 144 && different_blocks[i].first.size() == 3 &&
              different_blocks[i].first[0] == 2 &&
              different_blocks[i].first[1] == 3 &&
              different_blocks[i].first[2] == 10 && x == 1) {
            printf("THE TARGRT IS THE %d\n", x);
            for (int h = 0; h < different_blocks[j].first.size(); h++)
              printf("%d, ", different_blocks[j].first[h]);
          }
          if (i == 60 && div == 1) {
            printf("checking the div %d %d index %d\n", div, x, indx);
          }
        }
      }
    }
  }
  if (p)
    printf("%d %d %d opopopopopopoooppooppopopooppopopopopopopopopopopo\n",
           no_of_different_divisors, no_of_different_blocks, n_primes);
}
int get_block_differences(vector<int> x, vector<int> y) {
  int i = x.size() - 1, j = y.size() - 1;
  int ret = 0;
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  while (i >= 0 || j >= 0) {
    if (i < 0)
      ret += y[j];
    else if (j < 0)
      ret += x[i];
    else
      ret += abs(x[i] - y[j]);
    i--, j--;
  }
  return ret;
}
int get_number_index_in_block_array(int x) {
  vector<int> prime_dist = numPF(x);
  if (p) printf("joijio %d %d %d\n", x, prime_dist.size(), prime_dist[0]);
  for (int i = 0; i < no_of_different_blocks; i++) {
    if (p) {
      printf("the  another vector \n");
      for (int h = 0; h < different_blocks[i].first.size(); h++)
        printf("%d ", different_blocks[i].first[h]);
      printf("\n");
    }
    if (different_blocks[i].first == prime_dist) {
      if (p) {
        printf("the  vector \n");
        for (int h = 0; h < prime_dist.size(); h++)
          printf("%d ", prime_dist[h]);
        printf("\n");
      }
      return i;
    }
  }
  return -1;
}
vector<int> numPF(long long x) {
  int i = 0;
  vector<int> ret;
  if (x == 1) {
    ret.push_back(0);
    return ret;
  }
  long long pf = primes[i++];
  while (x != 1 && i < n_primes && x >= pf * pf) {
    int cnt = 0;
    while (x % pf == 0) {
      x /= pf;
      cnt++;
    }
    if (cnt) ret.push_back(cnt);
    pf = primes[i++];
  }
  if (x != 1) ret.push_back(1);
  sort(ret.begin(), ret.end());
  return ret;
}
int fn(int current, long long with_me, int beforeCnt) {
  int x = 60;
  if (with_me > 1) {
    if (p) {
      if (current == 1 && with_me == 256 && beforeCnt == 8)
        printf("winwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n");
    }
    block x;
    int div = 1;
    for (int i = 0; i < current; i++)
      x.first.push_back(tmp[i]), div = div * (tmp[i] + 1);
    if (p)
      if (div == 243) {
        printf(
            "BBBBBBBBBBBBBBBBBBBBBBOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOMMMM"
            "MMMMMMMMMMMM\n");
        for (int j = 0; j < current; j++) printf("%d ", tmp[j]);
        printf("\n");
      }
    sort(x.first.begin(), x.first.end());
    x.second = div;
    different_blocks[no_of_different_blocks++] = x;
  }
  if (current == n_primes || with_me * primes[current] > 1000009 * x) {
    return 1;
  }
  long long local = 1;
  int ret = 0;
  for (int i = 1; i <= beforeCnt && with_me * local < 1000009 * x; i++) {
    if (p) {
      if (current == 0)
        printf(
            "------------------------------------------------------------------"
            "------------- %d\n",
            i);
    }
    local *= primes[current];
    if (with_me * local >= 1000009 * x) break;
    tmp[current] = i;
    ret += fn(current + 1, with_me * local, i);
  }
  return ret + 1;
}
int sieve() {
  memset(v, 0, sizeof(v));
  v[0] = v[1] = 1;
  long long i, j;
  for (i = 2; i * i < 1000009; i++) {
    if (!v[i]) {
      for (j = i * i; j < 1000009; j += i) {
        v[j] = 1;
      }
    }
  }
  int index = 0;
  for (i = 2; i < 1000009; i++) {
    if (!v[i]) {
      primes[index++] = i;
    }
  }
  return index;
}
int make_array_of_different_divisors() {
  set<int> divisors_set;
  for (int i = 0; i < no_of_different_blocks; i++)
    divisors_set.insert(different_blocks[i].second);
  divisors_set.insert(1);
  int j = 0;
  for (set<int>::iterator it = divisors_set.begin(); it != divisors_set.end();
       it++) {
    int x = *it;
    pair<int, int> s;
    s.first = x;
    s.second = j;
    different_divisors.insert(s);
    if (p) {
      printf("before %d %d\n", x, j);
    }
    j += 4;
  }
  return divisors_set.size();
}
