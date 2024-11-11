n=int(input())
l=list(map(int,input().split()))
a,b=map(int,input().split())
s=0
for i in range(a,b):
    s+=l[i-1]
print(s)
