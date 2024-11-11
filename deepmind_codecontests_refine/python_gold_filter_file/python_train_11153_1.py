n=int(input())
a=list(input())
t=0
if(n==1):
    print(0)
    print(*a)
elif(n==2):
    if(a[0]!=a[1]):
        print(0)
        print(*a,sep='')
    else:
        print(1)
        if(a[0]=='R'):
            a[1]='G'
        elif(a[0]=='G'):
            a[1]='R'
        elif(a[0]=='B'):
            a[1]='R'
        print(*a,sep='')
else:
    
    for i in range(n-2):
        if(a[i]==a[i+1]):
            if(a[i]=='R' and a[i+2]!='B'):
                a[i+1]='B'
            elif(a[i]=='R' and a[i+2]!='G'):
                a[i+1]='G'
            elif(a[i]=='G' and a[i+2]!='B'):
                a[i+1]='B'
            elif(a[i]=='G' and a[i+2]!='R'):
                a[i+1]='R'
            elif(a[i]=='B' and a[i+2]!='G'):
                a[i+1]='G'
            elif(a[i]=='B' and a[i+2]!='R'):
                a[i+1]='R'
            t=t+1
    if(a[n-1]==a[n-2]):
        if(a[n-3]=='R' and a[n-1]!='B'):
            a[n-2]='B'
        elif(a[n-3]=='R' and a[n-1]!='G'):
            a[n-2]='G'
        elif(a[n-3]=='G' and a[n-1]!='B'):
            a[n-2]='B'
        elif(a[n-3]=='G' and a[n-1]!='R'):
            a[n-2]='R'
        elif(a[n-3]=='B' and a[n-1]!='G'):
            a[n-2]='G'
        elif(a[n-3]=='B' and a[n-1]!='R'):
            a[n-2]='R'
        t=t+1
    print(t)
    print(*a,sep='')