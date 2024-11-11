N,H=map(int,input().split())
ab=[list(map(int,input().split()))for _ in range(N)]
ab.sort()
M=ab[-1][0]
B=[b for a,b in ab]
B.sort()
B=B[::-1]
ans=0
for b in B:
    if H>0 and b>M:
        H-=b
        ans+=1
    else:
        break
ans+=0--max(0,H)//M
print(ans)