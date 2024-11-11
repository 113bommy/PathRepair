k,x = map(int,input().split())
print(*[x+i for i in range(-k+1, k)])