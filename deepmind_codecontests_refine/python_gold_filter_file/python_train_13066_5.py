# -*- coding: utf-8 -*-
# @Time    : 2021/2/1 3:39 下午
# @Author  : qu
# @Email   : quzhenqing@zju.edu.cn
# @File    : C. Pearls in a Row.py
from sys import stdin

n = int(stdin.readline().strip())
a = list(map(int, stdin.readline().split()))
s = set()
flag = False
index = 1
res1 = []
res2 = []

for i, v in enumerate(a):
    if not (v in s):
        s.add(v)
    else:
        s.clear()
        res1.append(index)
        res2.append(i + 1)
        index = i + 2
        flag = True
# print(n, a, flag)
if flag:
    if not res2[-1] == n:
        res2[-1] = n
    print(len(res1))
    for i, j in zip(res1, res2):
        print(i, j)
else:
    print(-1)
