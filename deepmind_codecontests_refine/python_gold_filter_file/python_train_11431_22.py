k,x = map(int,input().split())
tmp = [i for i in range(x-k+1, x+k)]
print(*tmp)