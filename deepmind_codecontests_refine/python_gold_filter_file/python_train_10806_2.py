_ = input()
V = list(map(int, input().split()))
C = list(map(int, input().split()))

print(sum(map(lambda p: max(0, p[0] - p[1]), zip(V, C))))
