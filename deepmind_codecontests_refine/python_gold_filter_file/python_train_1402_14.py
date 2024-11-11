l,r = map(int, input().split())
a,b,c = 0,0,0
if(abs(l-r) < 3 and l%2==1 or r%2==1 and abs(l-r) < 3 or l==r):
    print(-1)
else:
    if(l%2==0):
        a=l
        b=+l+1
        c=l+2
        print(a,b,c)
    elif(l%2==1):
        a=l+1
        b=l+2
        c=l+3
        print(a,b,c)
