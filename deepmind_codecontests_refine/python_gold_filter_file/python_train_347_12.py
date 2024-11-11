n=int(input())
jim=[]
p=list(map(int,input().split()))
if n==1 or n==2 or len(set(p))==1:
    print(-1)
elif n==3 and len(set(p))==2:
    ka=[x for x in p]
    if p[0]==p[-1]:
        print(-1)
    else:
        if p[0]==p[1]:
            print(2,3)
        else:
            print(1,2)
elif len(set(p))>=3:
    kam=list(set(p))
    jim.append(kam[0])
    jim.append(kam[1])
    jim.append(kam[2])
    jim.sort()
    da=p.index(jim[0])+1
    dra=p.index(jim[1])+1
    dla=p.index(jim[2])+1
    if dra<da and dra<dla:
        print(da,dla)
    else:
        print(dra,min(da,dla))
else:
    ka=[x for x in p]
    ka.sort(reverse=True)
    ja=sorted(p)
    lam=1
    for y in range(n):
        if p[y]!=p[lam]:
            p[y],p[lam]=p[lam],p[y]
            if p!=ja and p!=ka:
                print(y+1,lam+1)
                break
            else:
                p[y],p[lam]=p[lam],p[y]
        else:
            pass

                
    