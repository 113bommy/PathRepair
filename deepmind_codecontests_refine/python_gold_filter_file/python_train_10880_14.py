n = int(input())
ans  = (n // 2 + 1) // 2 - 1
ans *= (n + 1) % 2
print(ans)