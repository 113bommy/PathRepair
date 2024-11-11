N, M = map(int,input().split())
A = [str(input()) for _ in range(N)]
B = [str(input()) for _ in range(M)]
 
res = "No"

for i in range(N-M+1):
  for j in range(N-M+1):
    for k in range(M):
      if(A[i+k][j:j+M] != B[k]):
        break
      if(k==M-1):
        res="Yes"
          
print(res)