n,m=map(int,input().split())
a=list(input().split())
b=list(input().split())
t=int(input())
for _ in range(t):
    k=int(input())
    print(a[(k-1)%n]+b[(k-1)%m])