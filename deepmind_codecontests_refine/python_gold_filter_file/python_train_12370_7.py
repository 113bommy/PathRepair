n = int(input())

ans = abs(n)
for i in range(n > 0, 50, 2):
    if ans & (1 << i) == (1 << i):
        ans += (1 << (i + 1))
print(f'{ans:b}')
