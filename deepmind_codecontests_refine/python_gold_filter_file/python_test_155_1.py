t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    s=input()
    c=0;ms=0
    ma=[];ma1=[];mb=[];mb1=[]
    
    for j in range(len(s)):
        if(s[j]=='1'):
            c+=1
    ma=[[0 for i in range(2)] for j in range(c)]
    mb=[[0 for i in range(2)] for j in range(n-c)]
    c1=0;c2=0
    for j in range(len(s)):
        if(s[j]=='1'):
            ma[c1][0]=a[j];ma[c1][1]=j
            c1+=1
        else:
            mb[c2][0]=a[j];mb[c2][1]=j
            c2+=1
            
    ma.sort()
    mb.sort()
    ca=0;cb=0
    tr=[0]*n
    for j in range(c):
        tr[ma[c-j-1][1]]=n-j
    for j in range(n-c):
        tr[mb[n-c-j-1][1]]=n-c-j
    
        
   
    for j in range(n):
        print(tr[j],end=" ")
    print()