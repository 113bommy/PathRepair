
# -*- coding: utf-8 -*-
# @Date    : 2018-09-22 16:53:43
# @Author  : raj lath (oorja.halt@gmail.com)
# @Link    : http://codeforces.com/contest/1051/problem/C
# @Version : 1.0.0

from sys import stdin

max_val=int(10e12)
min_val=int(-10e12)

def read_int()     : return int(stdin.readline())
def read_ints()    : return [int(x) for x in stdin.readline().split()]
def read_str()     : return input()
def read_strs()    : return [x for x in stdin.readline().split()]

'''
Examples
inputCopy
4
3 5 7 1
outputCopy
YES
BABA
inputCopy
3
3 5 1
outputCopy
NO
'''
from collections import Counter
lens = read_int()
arrs = read_ints()
3
ans  = ["A"] * lens
arrc = Counter(arrs)

a =  sum([1 for x in arrs if arrc[x] == 1])
b = 0
for i in range(lens):
    if arrc[arrs[i]] == 1 and a > (b+1):
        ans[i] = 'B'
        a -= 1
        b += 1

for i in range(lens):
    if arrc[arrs[i]] > 2 and a == (b+1):
        ans[i] = "B"
        b += 1
        break
if a == b:
    print("YES")
    print(''.join(ans))
else:
    print("NO")













