n, t = map(int, input().rstrip().split())
l = []
for i in range(n):
    a, b = map(int, input().rstrip().split())
    l.append([a,b])
l.sort()
total = 2
for i in range(n-1):
    cor1 = l[i][0] + l[i][1]/2
    cor2 = l[i+1][0] - l[i+1][1]/2
    if abs(cor2-cor1)==t:
        total+=1
    elif abs(cor2-cor1)>t:
        total+=2

print(total)