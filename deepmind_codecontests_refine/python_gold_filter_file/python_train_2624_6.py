t=int(input())
for i in range(t):
    c,s=[int(i) for i in input().split()]
    if c>=s:
        print(s)
    elif c==1:
        print(s**2)
    elif c<s:
        if s%c==0:
            print(((s//c)**2)*c)
        else:
            rem=s%c
            each=s//c
            res=((each+1)**2)*rem
            final_rem=c-rem
            print(res+(each**2)*final_rem)