x, y, z, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))

ab = []
for i in a:
    for j in b:
        ab.append(i+j)
ab.sort(reverse=True)
ab = ab[:k]

abc = []
for i in ab:
    for j in c:
        abc.append(i+j)
        
abc.sort(reverse=True)
for i in abc[:k]:
    print(i)
