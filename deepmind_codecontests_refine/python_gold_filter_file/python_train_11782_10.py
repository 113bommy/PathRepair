#coding=utf-8
for q in range(int(input())):
    k,n,a,b=map(int,input().split())
    t=(k-b*n)
    if t<=0:
        print(-1)
    else:
        print(min((t-1)//(a-b),n))