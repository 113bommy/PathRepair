#!/usr/bin/python3

n = int(input())
a = list(set(map(int, input().split())))
n = len(a)

cnt = 0
for i in range(n):
    f = True
    for j in range(n):
        if i == j:
            continue
        if a[i] % a[j] == 0:
            f = False
    if f:
        cnt += 1

print(cnt)
