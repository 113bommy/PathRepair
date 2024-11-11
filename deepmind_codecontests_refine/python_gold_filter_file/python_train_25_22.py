t=int(input())
for i in range(0,t):
    n=int(input())
    sl1=sl2=cz=0
    for j in range(1,n+1):
        w=input()
        if(j==n-2):
            a=w[n-1]
            if(a=='1'): sl1+=1
        if(j==n-1):
            b=w[n-2]
            if(b=='1'): sl1+=1
            e=w[n-1]
            if(e=='1'): sl2+=1
        if(j==n):
            c=w[n-3]
            if(c=='1'): sl1+=1
            f=w[n-2]
            if(f=='1'): sl2+=1
    if((sl1==0 and sl2==0) or (sl1==3 and sl2==2)):
        print(2)
        print('%d %d' %(n-1,n))
        print('%d %d' %(n,n-1))
    if((sl1==0 and sl2==2) or (sl1==3 and sl2==0)):
        print(0)
    if((sl1==0 or sl1==3) and sl2==1):
        print(1)
        if(sl1==0):
            if(e=='0'): print('%d %d' %(n-1,n))
            else: print('%d %d' %(n,n-1))
        else:
            if(e=='1'): print('%d %d' %(n-1,n))
            else: print('%d %d' %(n,n-1))
    if((sl1==1 or sl1==2) and sl2==1):
        print(2)
        if(sl1==1):
            if(e=='0'): print('%d %d' %(n-1,n))
            else: print('%d %d' %(n,n-1))
        else:
            if(e=='1'): print('%d %d' %(n-1,n))
            else: print('%d %d' %(n,n-1))
        if(sl1==1):
            if(a=='1'): print('%d %d' %(n-2,n))
            if(b=='1'): print('%d %d' %(n-1,n-1))
            if(c=='1'): print('%d %d' %(n,n-2))
        else:
            if(a=='0'): print('%d %d' %(n-2,n))
            if(b=='0'): print('%d %d' %(n-1,n-1))
            if(c=='0'): print('%d %d' %(n,n-2))
    if((sl1==1 or sl1==2) and (sl2==0 or sl2==2)):
        if(sl2==0):
            print(3-sl1)
            if(a=='0'): print('%d %d' %(n-2,n))
            if(b=='0'): print('%d %d' %(n-1,n-1))
            if(c=='0'): print('%d %d' %(n,n-2))
        else:
            print(sl1)
            if(a=='1'): print('%d %d' %(n-2,n))
            if(b=='1'): print('%d %d' %(n-1,n-1))
            if(c=='1'): print('%d %d' %(n,n-2))