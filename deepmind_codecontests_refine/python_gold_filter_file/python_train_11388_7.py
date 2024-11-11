# Codeforces - Yaroslav and Permutations
# https://codeforces.com/contest/296/problem/A
#
# Author: eloyhz
# Date: Sep/04/2020
#


if __name__ == '__main__':
    n = int(input())
    a = [int(x) for x in input().split()]
    c = [0] * 1001
    for x in a:
        c[x] += 1
    if max(c) <= (n + 1) / 2:
        print('YES')
    else:
        print('NO')
#    if n > 1 and max(c) > round(n / 2):
 #       print('NO')
  #  else:
   #     print('YES')

