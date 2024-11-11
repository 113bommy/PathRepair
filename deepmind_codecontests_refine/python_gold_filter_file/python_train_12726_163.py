n=int(input())
for i in range(n):
    a,b=map(int,input().split())
    c=min(2,a-1)
    print(c*b)