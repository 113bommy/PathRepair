a,b = map(int,input().split())
print(*[i for i in range(b-a+1,a+b)])
