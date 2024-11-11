n,x=map(int,input().split())
a=list(int(input()) for _ in range(n))
print(n+((x-sum(a))//min(a)))