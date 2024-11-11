n,x=map(int,input().split())
M=[int(input()) for i in range(n)]
print((x-sum(M))//min(M)+n)