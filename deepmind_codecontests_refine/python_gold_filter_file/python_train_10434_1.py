import math
from decimal import *
import random
 
for _ in range(int(input())):
    n, k = map(int, input().split())
    ok= True
    arr = list(map(int,input().split()))
    mrk = [0 for i in range(60)]
    for i in range(n):
        if(arr[i]%k>=2):
            ok = False
            break
        else:
            while(arr[i]>0):
                j = 1
                cnt = 0
                while(j*k<=arr[i]):
                    j*=k
                    cnt+=1
                mrk[cnt]+=1
                arr[i]-=j
    if(ok):
        for i in range(60):
            if(mrk[i]>1):
                ok = False
                print('NO')
                break
        if(ok):
            print('YES')
    else:
        print('NO')
