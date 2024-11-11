x = list(input())
y = list(input())

z = []
for i in range(len(x)):
    if x[i] < y[i]:
        break
    z.append(y[i])

if len(z) == len(y):
    print(''.join(z))
else:
    print(-1)
