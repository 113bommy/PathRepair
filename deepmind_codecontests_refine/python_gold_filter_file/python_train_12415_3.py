#!/usr/bin/pypy3
def Mex(lst):
    mex = 0
    while mex in lst:
        mex += 1
    return mex


for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans = []
    count = 0
    while(a != list(range(n))):
        mex = Mex(a)
        count += 1
        if mex < n:
            a[mex] = mex
            ans.append(mex + 1)
        else:
            for i in range(n):
                if a[i] != i:
                    a[i] = mex
                    ans.append(i + 1)
                    break

    print(count)
    print(*ans)
