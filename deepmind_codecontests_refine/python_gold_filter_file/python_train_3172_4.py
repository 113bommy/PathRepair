a1 = []
a2 = []
x = int(input())
for i in range(x):
    a, b = map(int, input().split(' '))
    a1.append(a)
    a2.append(b)
print(max(max(a1)-min(a1), max(a2)-min(a2))**2)