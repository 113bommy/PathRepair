n=int(input())
t=list(map(int,input().split()))
a,b=map(int,input().split())
d=0
for i in range(a,b):
    d+=t[i-1]
print(d)