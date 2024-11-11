n = int(input())
n = n/2
a = [int(x) for x in input().split(" ")]
a.sort()
p1 = 1
p2 = 2

r1 = 0
r2 = 0

for element in a:
    r1 = r1 + abs(element-p1)
    r2 = r2 + abs(element-p2)
    p1 = p1 + 2
    p2 = p2 + 2

print(min(r1, r2))
