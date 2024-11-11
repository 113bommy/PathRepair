n=int(input())
a=list(map(int,input().split()))
s=0
a.sort()
s=sum(a[:n:2])-sum(a[1:n:2])

print(abs(s))