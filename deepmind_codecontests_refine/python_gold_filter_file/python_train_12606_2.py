n, m = map(int,input().split())
ori = 0
red = 0
dif = []
for i in range(n):
    x,y = map(int,input().split())
    ori += x
    red += y
    dif.append(x-y)
if ori <= m:
    print(0)
elif red > m:
    print(-1)
else:
    tot = ori - m 
    dif.sort(reverse = True)
    for i in range(n):
        tot -= dif[i]
        if tot <= 0:
            print(i+1)
            break
