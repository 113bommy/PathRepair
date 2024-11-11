import sys
input=sys.stdin.buffer.readline
t=1    
for __ in range(t):
    a=[]
    n=int(input())
    for i in range(n):
        b=list(map(int,input().split()))
        a.append(b)
    dr={}
    di={}
    for i in range(n):
        for j in range(n):
            dr[i+j]=dr.get(i+j,0)+a[i][j]
            di[i+n-j+1]=di.get(i+n-j+1,0)+a[i][j]
    ind1=[0]*2
    ind2=[0]*2
    maxi1=0
    maxi2=0
    for i in range(n):
        for j in range(n):
            #if maxi<(dr[i+j]+di[i+n-j+1]-a[i][j]):
            if ((i+j)&1)==1:
                if maxi1<=(dr[i+j]+di[i+n-j+1]-a[i][j]):    
                    maxi1=(dr[i+j]+di[i+n-j+1]-a[i][j])
                    ind1[0]=i+1
                    ind1[1]=j+1
            else:
                if maxi2<=(dr[i+j]+di[i+n-j+1]-a[i][j]):    
                    maxi2=(dr[i+j]+di[i+n-j+1]-a[i][j])
                    ind2[0]=i+1
                    ind2[1]=j+1
                    
    
    
    print(maxi1+maxi2)
    print(ind1[0],ind1[1],ind2[0],ind2[1])