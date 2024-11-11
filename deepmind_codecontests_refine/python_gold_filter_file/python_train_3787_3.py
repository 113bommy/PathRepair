n,t=map(int,input().split())
a=list(input())
#print(a[1])
for i in range(t):
    j=0
    while(j<n-1):
        #print(j)
        if(a[j]=='B' and a[j+1]=='G'):
            a[j],a[j+1]=a[j+1],a[j]
            j=j+1
        j+=1
for i in a:
    print(i,end='')

    
