k, x = map(int, input().split())

ans = list(range(x - k + 1, x+k))
print(*ans)
