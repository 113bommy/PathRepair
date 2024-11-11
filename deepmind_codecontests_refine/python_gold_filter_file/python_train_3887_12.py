n=int(input())
a=sorted(map(int,input().split()))
s=c=0
while s<=sum(a):
    s=s+a.pop()
    c=c+1

print(c)