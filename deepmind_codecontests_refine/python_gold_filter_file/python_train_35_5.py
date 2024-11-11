a=input()
n=len(a)
z=[31,28,31,30,31,30,31,31,30,31,30,31]
e=[[[0 for k in range(z[j])] for j in range(12)] for i in range(3)]
for i in range(n-9):
    if a[i+2]==a[i+5]=='-' and str(a[i]+a[i+1]).isdigit() and str(a[i+3]+a[i+4]).isdigit() and str(a[i+6]+a[i+7]+a[i+8]+a[i+9]).isdigit():
        b,c,d=int(a[i]+a[i+1]),int(a[i+3]+a[i+4]),int(a[i+6]+a[i+7]+a[i+8]+a[i+9])
        if 2013<=d<=2015 and 1<=c<=12 and 1<=b<=z[c-1]:
            e[d-2013][c-1][b-1]+=1
i=j=k=0
for i1 in range(3):
    for j1 in range(12):
        for k1 in range(z[j1]):
            if e[i1][j1][k1]>e[i][j][k]:
                i,j,k=i1,j1,k1
i,j,k=str(i+2013),str(j+1),str(k+1)
print('0'*(2-len(k))+k,'0'*(2-len(j))+j,i,sep='-')