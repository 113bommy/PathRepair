n=int(input())
d=list(map(int,input().split()))
d.sort()
s=d[n//2]-d[n//2-1]
print(s)