[n,m] = map(int,input().split())
s = input()
t = input()

mi = n+m
ml = []
for i in range(m-n+1):
    l = []
    for j in range(n):
        if s[j] != t[i+j]:
            l.append(j+1)
    if len(l) < mi:
        mi = len(l)
        ml = l
        
        

print(mi)
for i in ml:
    print(i,end=" ")