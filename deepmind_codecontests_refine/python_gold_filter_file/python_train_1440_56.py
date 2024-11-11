n,x=map(int,input().split())
l=[int(input()) for i in range(n)]
print(len(l)+(x-sum(l))//min(l))