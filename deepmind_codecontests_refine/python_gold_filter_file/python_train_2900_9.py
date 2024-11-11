i,o,t,j,l,s,z=map(int, input().split())
ans=o+j//2*2+l//2*2+i//2*2+(i&1 and j&1 and l&1)*3
k=min(i,j,l)
for n in range(max(0,k-10),k+1):
    ans=max(ans,o+n*3+(i-n)//2*2+(j-n)//2*2+(l-n)//2*2)
print(ans)