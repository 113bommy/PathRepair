from random import choice, randint
from string import ascii_uppercase, ascii_letters, digits, ascii_lowercase
from sys import stdin, stdout
from random import choice
from functools import reduce
import time
from math import *
from itertools import combinations
from decimal import *

'''s = set(list(input()))
subs = [set(j) for i in range(len(s)) for j in combinations(s, i + 1)]
print(len(subs))'''

'''n = int(input())
arr = (2 * list(map(int, input().split())))[::-1]
ans = [0] * n
for i in range(n):
    ans[arr[i + arr[i] - 1]] += 1
    #print(ans)
print(ans.index(max(ans)) + 1)'''


n = int(stdin.readline())
maxs, ans = [], []
arr = [0] * n
arr1 = [0] * n
cmin = - 10 ** 12
tmp = cmax = 10 ** 12
for i in range(n):
    s, g = map(int, stdin.readline().split())
    arr[i] = s
    #print(arr)
    arr1[i] = g
    cmax = min(s + g, cmax + 1)
    cmin = max(cmin - 1, s)
    if cmax < cmin:
        stdout.write('-1')
        exit()
    maxs.append(cmax)
for i in range(n - 1, -1, -1):
    tmp =  min(tmp + 1, maxs[i])
    ans.append(tmp)
#print(arr)
stdout.write(str(sum(ans) - sum(arr)) + '\n')
for i in ans[::-1]:
    stdout.write(str(i) + ' ')