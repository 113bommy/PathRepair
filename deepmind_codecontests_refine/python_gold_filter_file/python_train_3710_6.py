h1, a1, c1 = [int(i) for i in input().split()]
h2, a2 = [int(i) for i in input().split()]
a = []
while h2 > 0:
    if (h1 > a2) or (h2 - a1 <= 0):
        a.append('STRIKE')
        h2 -= a1
    else:
        a.append('HEAL')
        h1 += c1
    h1 -= a2
print(len(a))
for i in range(len(a)):
    print(a[i])