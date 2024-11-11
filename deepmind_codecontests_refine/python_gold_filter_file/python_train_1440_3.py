n,x = map(int,input().split())
M = [int(input()) for i in range(n)]
print(n+(x-sum(M))//min(M))