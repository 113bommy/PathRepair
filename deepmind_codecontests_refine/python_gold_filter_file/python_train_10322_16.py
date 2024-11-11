k = int(input())
a = [int(t) for t in input().split(' ')]

a = list(reversed(a))
print(min(k - a.index(0), k - a.index(1)))