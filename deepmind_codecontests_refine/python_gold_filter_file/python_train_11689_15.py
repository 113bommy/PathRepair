t = int(input())
a, b, c = [int(x) for x in input().split()]
d, e, f = [int(x) for x in input().split()]

max = min(a, e) + min(b, f) + min(c, d)
min = min(a, t-e) + min(b, t-f) + min(c, t-d)
print(t - min, max)
