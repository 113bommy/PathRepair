S=input()
N=len(S)
A=len([i for i in range(N) if str(i%2)==S[i]])
print(min(A,N-A))