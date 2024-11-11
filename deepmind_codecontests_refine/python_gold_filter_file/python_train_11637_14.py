N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))

cnt = 0
step = 0

for i in range(N):
    if A[step] == B[i]:
        cnt += 1
    else:
        step += 1



flag = 0

for j in range(300):
    C = B[cnt+j:]+B[:cnt+j]
    flag = 0
    for i in range(N):
        if A[i] == C[i]:
            flag = 1
            break
    if i == N-1 and flag == 0:
        break
    
    
if flag == 1:
    print('No')
else:
    print('Yes')
    print(' '.join(map(str, C)))