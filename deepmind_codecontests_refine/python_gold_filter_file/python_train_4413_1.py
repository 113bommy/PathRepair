import math

n=int(input())

d=list(map(int,input().split()))
x,y=map(int,input().split())

if x==y:
    print(0)
elif x<y:
    MIN=0
    for i in range(x-1,y-1):#y-1
        MIN+=d[i]
   # print(MIN)
    tmp=0
    step=y-1
    while step!=x-1:
        tmp+=d[step]
        step+=1
        if step==n:
            step=0
   # print(tmp)
    if tmp<MIN:
        MIN=tmp
    print(MIN)
else:
    MIN=0
    for i in range(y-1,x-1):#x-1
        MIN+=d[i]
   # print(MIN)
    tmp=0
    step=x-1
    while step!=y-1:
        tmp+=d[step]
        step+=1
        if step==n:
            step=0
   #print(tmp)
    if tmp<MIN:
        MIN=tmp
    print(MIN)