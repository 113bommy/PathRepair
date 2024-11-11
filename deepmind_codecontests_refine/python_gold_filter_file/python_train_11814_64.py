m=['0','0']
m=input().split()
m[0]=int(m[0])
m[1]=int(m[1])
if(m[0]>0 and m[1]>0 and m[0]<17 and m[0]<=m[1]):
    print((m[0]*m[1])//2)
