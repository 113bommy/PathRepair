from sys import stdin, stdout
import heapq as hq
from collections import defaultdict

t = int(input())
for tc in range(t):
    n = int(stdin.readline())
    res1=[]
    res2=[]
    res=[]
    for i in range(n):
        if i%2==0:
            res1.append(i+1)
        else:
            res2.append(i+1)
    res1=res1[::-1]
    for i in range(n//2):
        res.append(res2[i])
        res.append(res1[i])
    if n%2==1:
        res.append(res1[-1])
    res_s=" ".join([str(x) for x in res])

    stdout.write(str(res_s) + "\n")