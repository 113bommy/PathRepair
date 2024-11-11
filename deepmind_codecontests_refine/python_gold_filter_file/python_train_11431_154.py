k, x =map(int, input().split())
s = [i for i in range(x-k+1,x+k)]
print(*s)