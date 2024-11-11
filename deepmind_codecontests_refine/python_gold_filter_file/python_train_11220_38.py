N=int(input())
S=list(map(int,input().split()))
D=sorted(S)
A=1

for i in range(N):
    A=A*D[i]
    if A>10**(18):
        A=-1
        break
print(A)