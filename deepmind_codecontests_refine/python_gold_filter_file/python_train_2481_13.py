n=int(input())
d,x=map(int,input().split())
print(x+n+sum((d-1)//int(input()) for _ in range(n)))