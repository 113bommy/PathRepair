for TS in range(int(input())):
    R,r,BIG,small=map(int,input().split())
    if abs(R-r)%(BIG+small)!=0:
        print(-1)
        continue
    else:
        print((r-R)//(BIG+small))
