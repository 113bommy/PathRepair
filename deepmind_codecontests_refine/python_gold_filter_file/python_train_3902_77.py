y, x = map(int, input().split())
t = True
arr = []
for i in range(y):
    if i % 2 == 0:
        arr.append('#'*x)
    else:
        if t == True:
            arr.append('.'*(x-1)+'#')
            t = False
        elif t == False:
            arr.append('#'+'.'*(x-1))
            t = True
for i in range(y):
    print(*arr[i], sep='')