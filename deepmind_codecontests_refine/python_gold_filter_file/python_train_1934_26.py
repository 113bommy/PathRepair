n = int(input())
ans = [2] * (n // 2)
if n % 2:
    ans[-1] = 3
print(len(ans))
print(*ans)