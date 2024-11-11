n=int(input())
l=[2,1]
for _ in range(100):
    l.append(l[-1]+l[-2])
print(l[n])