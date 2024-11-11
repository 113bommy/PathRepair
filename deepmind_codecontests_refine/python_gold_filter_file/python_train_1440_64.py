n,x=map(int,input().split())
L=[int(input()) for i in range(n)]
print(n+(x -sum(L))//min(L))