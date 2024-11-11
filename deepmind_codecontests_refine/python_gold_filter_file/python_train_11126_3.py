n = int(input())
d = {t[0]: t[1] for t in [list(map(int, input().split())) for _ in range(n)]}
print(*max(d.items(), key=lambda x: x[1]))