# coding: utf-8
n = int(input())
A = list(map(int, input().split()))
X = [0]*(n+1)
for a in A:
    X[a] += 1
s = 0
for x in X:
    s += x*(x-1)//2
for a in A:
    print(s-X[a]+1)