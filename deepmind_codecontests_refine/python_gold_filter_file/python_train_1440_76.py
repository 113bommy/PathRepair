n,x=map(int,input().split())
ln=[int(input()) for _ in range(n)]
print(n+(x-sum(ln))//min(ln))