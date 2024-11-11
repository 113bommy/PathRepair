for i in range(int(input())):
    n=int(input())
    maxl=0
    minr=1000000000
    if n==1:
        l,r=map(int,input().split())
        print(0)
    else:
        f=0
        prevl=-1
        prevr=-1
        for i in range(n):
            l,r=map(int,input().split())
            if f==0:    
                if prevl==-1:
                    prevl=l
                    prevr=r
                else:
                    if not((l<=prevr and l>=prevl) or (r>=prevl and r<=prevr)or (r>=prevr and l<=prevl)):
                        f=1
                        prevl=l
                        prevr=r
                    elif f==0:
                        prevl=max(l,prevl)
                        prevr=min(r,prevr)
            if maxl<l:
                maxl=l
            if minr>r:
                minr=r
        if f==0:
            print(0)
        else:
            print(max(maxl,minr)-min(maxl,minr))