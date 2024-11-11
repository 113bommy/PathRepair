n, _ = map(int, input().split())

print(*sorted([input() for _ in range(n)]), sep="")