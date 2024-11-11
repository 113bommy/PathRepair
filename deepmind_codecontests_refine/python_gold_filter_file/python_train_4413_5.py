n = int(input())
d = [int(x) for x in input().split()]
a, b = [int(x) for x in input().split()]
a, b = min(a, b), max(a, b)
a -= 1
b -= 1
print(min(sum(d[a:b]), sum(d[:a] + d[b:])))