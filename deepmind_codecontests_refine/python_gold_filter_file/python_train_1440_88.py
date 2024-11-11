n,x = map(int, input().split())
a = [int(input()) for i in range(n)]
print((x-sum(a))//min(a) + n)