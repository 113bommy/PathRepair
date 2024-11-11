# Fast IO (be careful about bytestring)

import os,io
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

for _ in range(int(input())):
    n,k = map(int,input().split())
    s = input()
    zeroCount = 0
    oneCount = 0
    contradiction = False
    for i in range(k):
        cnt = i
        mustBeZero = False
        mustBeOne = False
        while cnt < n:
            if s[cnt] == ord("0"):
                mustBeZero = True
            if s[cnt] == ord("1"):
                mustBeOne = True
            cnt += k
        if mustBeZero and mustBeOne:
            contradiction = True
            break
        elif mustBeOne:
            oneCount += 1
        elif mustBeZero:
            zeroCount += 1
    if contradiction:
        print("NO")
    elif oneCount <= k // 2 and zeroCount <= k // 2:
        print("Yes")
    else:
        print("NO")