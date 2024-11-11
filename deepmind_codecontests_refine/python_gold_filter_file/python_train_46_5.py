n = int(input())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
c = [int(i) for i in input().split()]
a1, b1, c1 = dict(), dict(), dict()
for i in c:
    c1[i] = c1.get(i, 0) + 1
for i in b:
    b1[i] = b1.get(i, 0) + 1
    if b1[i] > c1.get(i, 0):
        c2 = i
for i in a:
    a1[i] = a1.get(i, 0) + 1
    if a1[i] > b1.get(i, 0):
        b2 = i
print(b2)
print(c2)