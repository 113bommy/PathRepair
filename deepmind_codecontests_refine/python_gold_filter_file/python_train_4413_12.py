n = int(input())
l = list(map(int, input().split()))
a, b = map(int, input().split())
s = 0
s1 = 0
if a > b:
    a, b = b, a
a -= 1
b -= 1
for i in range(a, b, 1):
    s += l[i]
for i in range(b, n, 1):
    s1 += l[i]
for i in range(0, a, 1):
    s1 += l[i]
print(min(s, s1))