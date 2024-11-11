N=int(input())
S=[input() for i in range(N)]
a=0
for i in range(N):
    for j in range(N-1):
        for k in range(j+1,N):
            if S[(j+i)%N][k]!=S[(k+i)%N][j%N]:
                break
        else:
            continue
        break
    else:
        a+=1
print(a*N)