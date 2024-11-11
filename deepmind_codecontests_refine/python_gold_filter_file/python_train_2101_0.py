a=int(input())
for i in range(a):
    b=input()
    c=input()
    k=c.rfind('1')
    s=len(c)-k
    l=0
    h=b[0:len(b)-s+1]
    for i in range(len(h)-1,-1,-1):
        if(h[i]=='1'):
            l=len(h)-i-1
            break
    print(l)