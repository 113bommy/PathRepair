n,m=map(int,input().split())
L=list(int(input()) for i in range(n))
print(n+(m-sum(L))//min(L))