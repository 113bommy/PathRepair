N,M=map(int,input().split())
A=list(map(int,input().split()))
BC=[list(map(int,input().split())) for  _ in range(M)]#リストの表記が違う
BC.sort(key=lambda x: -x[1])#リバースと-1の違い

for b,c in BC:
    A.extend([c]*b)
    if len(A)>N*2:
        break
A.sort(reverse=True)
print(sum(A[:N]))