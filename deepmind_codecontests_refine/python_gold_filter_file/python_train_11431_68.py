k, x= map(int, input().split())
ans = [i for i in range(x-k+1, x+k)]
print(*ans)