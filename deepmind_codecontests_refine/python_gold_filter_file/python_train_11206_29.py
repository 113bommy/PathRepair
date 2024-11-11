ost = {}
stop = False
n, k = map(int, input().split(' '))
for i in range(k):
    try:
        x = ost[n % (i+1)]
        stop = True
        break
    except:
        ost[n % (i+1)] = 0
if stop:
    print('No')
else:
    print('Yes')
