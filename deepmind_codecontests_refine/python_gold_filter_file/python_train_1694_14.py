import sys
from collections import defaultdict
# input=sys.stdin.readline

for _ in range(int(input())):
    n=int(input())
    a=list(input())
    b=list(input())
    res=[]
    for i in range(n-1,-1,-1):
        if a[i]==b[i]:
            continue
        if b[i]=="0":
            if a[0]=="0":
                a[0]="1"
                res.append(1)
            res.append(i+1)
        else:
            if a[0]=="1":
                a[0]=="0"
                res.append(1)
            res.append(i+1)
        for j in range(i+1):
            if a[j]=="1":
                a[j]="0"
            else:
                a[j]="1"
        for j in range((i+1)//2):
            a[j],a[i-j]=a[i-j],a[j]
    print(len(res),*res)