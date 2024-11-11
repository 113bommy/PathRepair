n,x=map(int,input().split())
D=[int(input()) for _ in range(n)]
print(n+(x-sum(D))//min(D))