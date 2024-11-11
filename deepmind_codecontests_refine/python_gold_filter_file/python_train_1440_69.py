n,x = map(int,input().split())
l = [int(input()) for i in range(n)]
print((x-sum(l))//min(l)+n)
