N,X=map(int,input().split())
A=[int(input()) for i in range(N)]
print(N+(X-sum(A))//min(A))