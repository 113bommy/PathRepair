n,m,s,f=map(int,input().split())
d={}
final=0
for i in range(m):
    a=list(map(int,input().split()))
    d[a[0]]=[a[1],a[2]]
    final=a[0]
z=""
if s<f:
    i=0
    while s!=f:
        i+=1
        if i not in d:
            s+=1
            z+="R"
        elif (s not in range(d[i][0],d[i][1]+1)) and (s+1 not in range(d[i][0],d[i][1]+1)):
            s+=1
            z+="R"
        else:
            z+="X"
        if s==f:
            break
else:
    i=0
    while s!=f:
        i+=1
        if i not in d:
            s -= 1
            z += "L"
        elif (s not in range(d[i][0], d[i][1] + 1)) and (s - 1 not in range(d[i][0], d[i][1] + 1)):
            s-=1
            z+="L"
        else:
            z+="X"
        if s==f:
            break
print(z)