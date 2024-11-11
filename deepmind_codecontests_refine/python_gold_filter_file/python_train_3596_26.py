x,y=list(map(int,input().split(" ")))
z=[]
for i in range(x):
    t=list(input().split(" "))
    z.append(t)

s=y
c=0
for i in z:
    
    if i[0] == '+':
        s=s+int(i[1])
    else:
        if int(i[1])<= s:
            s=s-int(i[1])
        else:
            c=c+1

print(str(s),str(c))