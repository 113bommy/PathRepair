n = int(input())
x = []
x = list(map(int,input().split(' ')))
y = []
for i in range(len(x)):
    y.append(x[i])

y.sort()

#print(x)
#print(y)

b = int(n/2)
s = int(n/2)-1

if n == 2:
    print(x[1])
    print(x[0])
else:
    for i in range(n):
        if x[i] >= y[b]:
            print(y[s])
        else:
            print(y[b])
