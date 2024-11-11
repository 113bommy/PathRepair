n=int(input())
s=int(input())

No=0
if n==s:
    print(n+1)
    No =1
else:
    for b in range(2,int(n**0.5)+2):
        m=0
        N=n
        while N!=0:
            m+=N%b
            N=N//b
            if m>s:
                break    
        if m==s:
            print(b)
            No=1
            exit()
    for p in range(int(n**0.5-1),0,-1):
        b = float(n-s)/float(p)+1.0
        if abs(b-int(b))<10**(-10)and b>0:
            b=int(b)
            m=0
            N=n
            while N!=0:
                m+=N%b
                N=N//b
                if m>s:
                    break    
            if m==s:
                print(b)
                No=1
                exit()
if No==0:
    print(-1)