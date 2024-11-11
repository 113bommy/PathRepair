from collections import Counter,defaultdict
from sys import stdin, stdout
input = stdin.readline
I =lambda:int(input())
M =lambda:map(int,input().split())
LI=lambda:list(map(int,input().split()))
for _ in range(int(input())):
    s=int(input())
    n=int(input())
    a=list(str(n));ans=0
    for i in range(len(a)):
        if int(a[i])%2:
            ans+=1
        if ans==2:
            break
        
    if n==1:
        print(-1)
    elif ans==2:
        for i in range(len(a)):
            print(a[i],end="")
            if int(a[i])%2:
                ans-=1
            if ans==0:
                print();break
    else:
        print(-1)


        
