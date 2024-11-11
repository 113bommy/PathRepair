n,x=map(int,input().split())
ln=[int(input()) for i in range(n)]
print(n+(x-sum(ln))//min(ln))