tst=int(input())
for isa in range(tst):
    nsa=int(input())
    ssa=input()
    csa=0
    osa=0
    for jsa in range(nsa):
        if(ssa[jsa]=='('):
            osa=osa+1
        else:
            if(osa==0):
                csa=csa+1
            else:
                osa=osa-1
    print(csa)