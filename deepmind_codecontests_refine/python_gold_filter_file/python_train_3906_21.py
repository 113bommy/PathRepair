I = lambda: map(int, input().split())

n, s = I()

print(max(s, max(sum(I()) for _ in range(n))))