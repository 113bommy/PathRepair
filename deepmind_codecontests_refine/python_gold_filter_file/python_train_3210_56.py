a, b, k = map(int, input().split())
x = range(a, b+1)

for i in sorted(set(x[:k]) | set(x[-k:])):
    print(i)