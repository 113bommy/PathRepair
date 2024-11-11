import copy
H,W,K=map(int,input().split())
S=[]
for _ in range(H):
    S.append([int(x) for x in list(input())])

ans=(H-1)+(W-1)

for i in range(2**(H-1)):
    check=[0]*H
    for j in range(H-1):
        if ((i>>j)&1):
            check[j+1]=check[j]+1
        else:
            check[j+1]=check[j]
    
    g=check[H-1]+1
    A=[0]*g
    c=0
    f=0
    for j in range(W):
        B=[0]*g
        for k in range(H):
            if S[k][j]==1:
                B[check[k]]+=1
            if B[check[k]]>K:
                c=10**4
                f=1
                break
        if f:
            break
        #print("AB",A,B)
        for l in range(g):
            if A[l]+B[l]>K:
                c+=1
                A=copy.copy(B)
                break
            else:
                A[l]+=B[l]
    ans=min(ans,c+g-1)

print(ans)


