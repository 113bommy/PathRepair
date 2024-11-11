N=int(input())
B=["*"]+list(map(int,input().split()))

X=[]
for t in range(N):
    p=-1
    for k in range(1,(N-t)+1):
        if B[k]==k:
            p=k

    if p>=1:
        X.append(p)
        del B[p]
    else:
        print(-1)
        exit()

print("\n".join(map(str,X[::-1])))
