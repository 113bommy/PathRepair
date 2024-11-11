sol=int(input())
list1=[]
for i in range(10**5+1):
    list1.append([])
for i in range(sol):
    a,b=input().split()
    b=int(b)
    list1[b].append(a)
i=0
v=True
while i<10**5+1 and v:
    j=0
    z=-1
    while j<len(list1[i]) and v:
        if (int(list1[i][j])-z)==1:
            z=int(list1[i][j])
        elif int(list1[i][j])-z>1:
            v=False
        j+=1
    i+=1
if v==True:
    print("YES")
else:
    print("NO")
