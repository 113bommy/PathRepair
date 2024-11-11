x = int(input())
y = [int(i) for i in input().split()]
z = [-1]
k = 0
for i in range(x):
    for j in range(x):
        for q in range(x):
            if i != j and j != q and i != q:
                if y[i]+y[j]+y[q]==2*max(y[i], y[j], y[q]):
                    z = [max(y[i], y[j], y[q]), y[i]+y[j]+y[q]-min(y[i], y[j], y[q])-max(y[i], y[j], y[q]), min(y[i], y[j], y[q])]
                    
                    k = 1
            if k == 1:
                break
        if k == 1:
            break
    if k == 1:
        break
if len(z) != 1:
    print(y.index(z[0])+1, y.index(z[1])+1, end=' ')
    for i in range(x-1, -1, -1):
        if y[i] == z[2]:
            print(i+1)
            break
else:
    print(-1)
