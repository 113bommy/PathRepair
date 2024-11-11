from bisect import bisect_left
n=input()
b=list(map(int,input().split()))
for i in range(1,len(b)):
    b[i]+=b[i-1]
m=int(input())
t=list(map(int,input().split()))


for i in t:
    a=bisect_left(b,i)
    if a==len(b):
        print(n)
    else:
        print(a+1)






