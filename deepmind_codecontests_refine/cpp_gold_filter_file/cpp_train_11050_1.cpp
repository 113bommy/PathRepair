#include <bits/stdc++.h>
using namespace std;
char str[2010];
char str_begin[2010];
char str_end[2010];
long long value_str_one[2010];
long long value_begin_one;
long long value_end_one;
long long value_str_two[2010];
long long value_begin_two;
long long value_end_two;
const int base = 111;
const int mod_one = 3e5 + 17;
const int mod_two = 217636919;
long long exp_one[2010];
long long exp_two[2010];
struct node {
  long long hash_two;
  node *next;
  node(long long ht, node *n = NULL) {
    hash_two = ht;
    next = n;
  }
};
node *hash_map[mod_one + 10];
int flag_head[2010];
int flag_tail[2010];
void find(long long key_one, long long key_two) {
  if (hash_map[key_one] == NULL)
    hash_map[key_one] = new node(key_two, NULL);
  else {
    node *tmp = hash_map[key_one];
    while (tmp->hash_two != key_two && tmp->next != NULL) tmp = tmp->next;
    if (tmp->hash_two != key_two)
      tmp->next = new node(key_two);
    else
      ;
  }
}
int main() {
  exp_one[0] = 1;
  exp_two[0] = 1;
  for (int i = 1; i <= 2000; i++) {
    exp_one[i] = (exp_one[i - 1] * base) % mod_one;
    exp_two[i] = (exp_two[i - 1] * base) % mod_two;
  }
  int len_str, len_begin, len_end;
  cin.getline(str, 3000, '\n');
  cin.getline(str_begin, 3000, '\n');
  cin.getline(str_end, 3000, '\n');
  len_str = strlen(str);
  len_begin = strlen(str_begin);
  len_end = strlen(str_end);
  for (int i = 0; i < len_str; i++) {
    value_str_one[i + 1] =
        (base * value_str_one[i] % mod_one + str[i] - 'a' + 2) % mod_one;
    value_str_two[i + 1] =
        (base * value_str_two[i] % mod_two + str[i] - 'a' + 2) % mod_two;
  }
  for (int i = 0; i < len_begin; i++) {
    value_begin_one *= base;
    value_begin_one += str_begin[i] - 'a' + 2;
    value_begin_one %= mod_one;
    value_begin_two *= base;
    value_begin_two += str_begin[i] - 'a' + 2;
    value_begin_two %= mod_two;
  }
  for (int i = 0; i < len_end; i++) {
    value_end_one *= base;
    value_end_one += str_end[i] - 'a' + 2;
    value_end_one %= mod_one;
    value_end_two *= base;
    value_end_two += str_end[i] - 'a' + 2;
    value_end_two %= mod_two;
  }
  for (int i = 0; i <= len_str - len_begin; i++) {
    long long tmp_one =
        (value_str_one[i + len_begin] -
         (value_str_one[i] * exp_one[len_begin] % mod_one) + mod_one) %
        mod_one;
    long long tmp_two =
        (value_str_two[i + len_begin] -
         (value_str_two[i] * exp_two[len_begin] % mod_two) + mod_two) %
        mod_two;
    if (tmp_one == value_begin_one && tmp_two == value_begin_two)
      flag_head[i + 1]++;
  }
  for (int i = 0; i <= len_str - len_end; i++) {
    long long tmp_one =
        (value_str_one[i + len_end] -
         (value_str_one[i] * exp_one[len_end] % mod_one) + mod_one) %
        mod_one;
    long long tmp_two =
        (value_str_two[i + len_end] -
         (value_str_two[i] * exp_two[len_end] % mod_two) + mod_two) %
        mod_two;
    if (tmp_one == value_end_one && tmp_two == value_end_two)
      flag_tail[i + len_end]++;
  }
  int space = len_begin > len_end ? len_begin : len_end;
  for (int i = 1; i <= len_str; i++) {
    if (flag_head[i] != 0) {
      for (int k = i + space - 1; k <= len_str; k++) {
        if (flag_tail[k] != 0) {
          long long key_one =
              (value_str_one[k] -
               (value_str_one[i - 1] * exp_one[k - i + 1] % mod_one) +
               mod_one) %
              mod_one;
          long long key_two =
              (value_str_two[k] -
               (value_str_two[i - 1] * exp_two[k - i + 1] % mod_two) +
               mod_two) %
              mod_two;
          find(key_one, key_two);
        }
      }
    }
  }
  long long counter = 0;
  for (int i = 0; i < 3e5 + 17; i++) {
    if (hash_map[i] != NULL) {
      node *tmp = hash_map[i];
      while (tmp != NULL) {
        counter++;
        tmp = tmp->next;
      }
    }
  }
  cout << counter;
  return 0;
}
