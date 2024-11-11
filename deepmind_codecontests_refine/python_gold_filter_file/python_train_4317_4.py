import bisect

n = int(input())
a = map(int, input().split())
b = [1]
for x in a:
    b.append(b[-1]+x)

m = int(input())
c = map(int, input().split())
for x in c:
    print(bisect.bisect(b, x))
