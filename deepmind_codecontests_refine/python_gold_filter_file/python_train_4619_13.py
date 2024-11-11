n=int(input())
m=[]
for i in range(n):
    l=[]
    l=[int (i) for i in input().split()]
    m.append(l)

a=[]
for i in range(n):
    c=0
    for j in range(len(m[i])):
        if m[i][j]:
            c+=1
    a.append(c)

k=0
for i in a:
    if i>=2:
        k+=1
print(k)
        
            