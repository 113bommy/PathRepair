n=int(input())
x=list(map(int,input().split()))
x.sort()
print(x[n//2]-x[n//2-1])