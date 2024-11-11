'''input
4
2
2 1
3
1 2 1
4
2 4 1 3
5
2 5 1 4 3

'''
from sys import stdin,stdout
# from collections import Counter
for t in range(int(stdin.readline())):
    n = int(stdin.readline())
    a = list(map(int,stdin.readline().strip().split()))
    a_sorted = sorted(a)
    # print(a_sorted)
    res = []
    for i in range(n-1,-1,-1):
        if a_sorted[i]!=a[i]:
            # print("before:",a)
            idx = a.index(a_sorted[i])
            a = a[:idx]+a[idx+1:i+1]+[a[idx]]+a[i+1:]
            res.append((idx,i,1))
            # print("after:",a,idx)
    # print(a)
    print(len(res))
    for l,r,d in res:
        print(l+1,r+1,d)