a, b, x = list(map(int, input().split()))

ans = b//x - (a-1)//x
print(ans)
