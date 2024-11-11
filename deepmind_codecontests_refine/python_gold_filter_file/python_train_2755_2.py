n=int(input())
l=[int(i) for i in input().split()]
z,mi=[],None
if(len(l)==3):
    print(l[2]-l[0])
else:   
    for j in range(n):
        if(j>0):
            z.append(l[j]-l[j-1])
        if(j>1):
            if(mi==None):
                mi=j-2
            elif(z[mi]+z[mi+1]>z[j-2]+z[j-1]):
                mi=j-2
    print(max(z[mi]+z[mi+1],max(z)))