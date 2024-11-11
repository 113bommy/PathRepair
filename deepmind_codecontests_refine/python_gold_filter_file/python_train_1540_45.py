a, b = map(int, input().split())
c = sum(map(int, input().split()))

print(max(a - c, -1))