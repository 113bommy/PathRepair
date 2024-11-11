x, n = map(int, input().split())
a = set(map(int, input().split()))
print(min((i for i in range(102) if i not in a), key=lambda y:abs(x-y)))
