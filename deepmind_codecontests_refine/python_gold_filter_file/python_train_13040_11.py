test=int(input())
for t in range(test):
    n=int(input())
    c=list(map(int,input().split(" ")))
    o=list(map(int,input().split(" ")))
    c_min=min(c)
    o_min=min(o)
    op=0
    for x in range(len(c)):
        if c[x]>c_min and o[x]>o_min:
             choco=c[x]-c_min
             orange=o[x]-o_min
             op+=max([choco,orange])
        elif c[x]>c_min:
            op+=c[x]-c_min
        elif o[x]>o_min:
            op+=o[x]-o_min
    print(op)