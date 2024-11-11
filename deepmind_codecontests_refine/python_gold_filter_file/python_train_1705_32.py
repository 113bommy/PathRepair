a, b = map(int, input().split())
a, b = max(a, b), min(a, b)
print(b+1)

for i in range(b+1):
    print(b-i, i)