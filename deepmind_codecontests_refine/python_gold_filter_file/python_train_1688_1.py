t=int(input())
c=[]
for i in range(t):
    a=input()
    b=input()
    c.append([a,b])


for i in c:
    z=[]
    for j in i[0]:
        z.append(j)
    q=0
    for j in range(len(i[1])-len(i[0])+1):
        y=[]
        t=i[1][j:j+len(i[0])]
        for p in t:
            y.append(p)
        k=0
        for f in y:
            if y.count(f)!=z.count(f):
                break
            else:
                k+=1
        if k==len(i[0]):
            q=1
            print("YES")
            break
    if q==0:
        print("NO")