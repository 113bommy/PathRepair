a, b, c = map(int, input().split())
print(b if a==c else a if b==c else c)