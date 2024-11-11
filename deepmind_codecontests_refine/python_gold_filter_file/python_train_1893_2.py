from sys import stdin
input=stdin.readline
#import bisect
#i = bisect.bisect_left(a, k)
a=[]
#ans=0
n=int(input())
for _ in range (n):
    s=input()
    a.append(s)
m=int(input())
#n,k=map(int, input().split())
b=list(map(int, input().split()))
c=[0]*m
k=0
for i in range(1,m-1):
    if k==1:
        k=0
        continue
    if a[b[i-1]-1][b[i+1]-1]=='0' and b[i-1]!=b[i+1]:
        k=1    
        c[i]=1
print(c.count(0))
for i in range(m):
    if c[i]==0:
        print(b[i],end=" ")

    #YOUR CODE HERE