n, l = map(int, input().split())
a = range(l, l + n)
print(sum(a) - min(a, key=abs))