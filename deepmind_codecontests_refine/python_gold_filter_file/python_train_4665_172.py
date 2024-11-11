n=int(input())>>1
d=list(map(int,input().split()))
d.sort()
print(d[n]-d[n-1])