c = list(input().split())
a = []
for i in range(3):
    a.append([])
    
for n in c:
    if n[1]=='p':
        a[0].append(int(n[0]))
    elif n[1]=='m':
        a[1].append(int(n[0]))
    else:
        a[2].append(int(n[0]))

m = 2
for i in range(3):
    a[i].sort()
    if len(a[i])==3 and a[i][0]==a[i][1] and a[i][1]==a[i][2]:
        m = 0
    if len(a[i])==3 and a[i][1]-a[i][0]==1 and a[i][2]-a[i][1]==1:
        m = 0
    if len(a[i])==3 and (a[i][1]-a[i][0]<=2 or a[i][2]-a[i][1]<=2):
        m = min(m,1)
    if len(a[i])==2 and a[i][1]-a[i][0] in [0,1,2] :
        m = min(m,1)

if c[0]==c[1] and c[1]==c[2]:
    m = 0
print(m)