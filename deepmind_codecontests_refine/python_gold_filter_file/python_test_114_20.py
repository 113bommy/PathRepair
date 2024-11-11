import math
t = int(input())
for q in range(t):
    n=int(input())
    arr=list(map(int,input().split()))
    mn=min(arr)


    c=0
    for i in range(len(arr)):

        if arr[i]!=mn:
            c+=1
            print(arr[i],mn)
            if c==n//2:break





