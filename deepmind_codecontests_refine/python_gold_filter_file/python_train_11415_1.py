l, r = map(int, input().split())
two = []
three = []
for i in range(31):
    two.append(2 ** i)
for i in range(20):
    three.append(3 ** i)
s = set()
for i in range(31):
    for j in range(20):
        s.add(two[i] * three[j])
k = 0
for i in s:
    if l <= i <= r:
        k += 1
print(k)
