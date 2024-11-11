n=int(input())
A=list(map(int,input().split()))
A.sort(reverse=True)
Ans=[0]*n
Ans[0]=A[0]
if n%2==0:
    for i in range(1,n//2):
        Ans[i]=A[2*i-1]
        Ans[-i]=A[2*i]
    Ans[n//2]=A[-1]
else:
    for i in range(1,n//2+1):
        Ans[i]=A[2*i-1]
        Ans[-i]=A[2*i]
for i in range(n):
    if Ans[i]>=Ans[(i-1)%n]+Ans[(i+1)%n]:
        print('NO')
        break
else:
    print('YES')
    print(*Ans)