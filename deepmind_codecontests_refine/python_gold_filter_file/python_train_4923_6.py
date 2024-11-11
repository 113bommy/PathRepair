t=int(input())
for i in range(t):
    n,c0,c1,h=list(map(int,input().split()))
    s=input()
    a0=0
    a1=0
    for j in range(n):
        if s[j]=='0':
            a0+=1
        else:
            a1+=1
    
    print(min(c0*a0+c1*a1,h*a0+n*c1,h*a1+n*c0))