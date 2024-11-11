n = int(input())
t = [int(x) for x in input().split()]
a = t.index(max(t))
t.reverse()
b = t.index(min(t))
if a+b >= n:
    print(a+b-1)
else:
    print(a+b)
