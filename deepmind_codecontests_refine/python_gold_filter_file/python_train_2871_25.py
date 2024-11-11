N=int(input())
A=list(map(int, input().strip().split()))[:N]
B=[]
if N % 2==1:
    for k in range (0,(N-1)//2):
        B.append(A[N-2*k-1])
        B.append(A[2*k+1])
    B.append(A[0])
    print(*B)
elif N==2:
    print(str(A[1])+' '+str(A[0]))
elif N%2==0 and N//2 %2==0:
    for k in range (0,N//4-1):
        B.append(A[N-2*k-1])
        B.append(A[2*k+1])
    B.append(A[N//2+1])
    B.append(A[N//2-1])
    B.append(A[N//2])
    for i in range (0,N//4-1):
        B.append(A[N//2-2*i-2])
        B.append(A[N//2+2*i+2])
    B.append(A[0])
    print(*B)
elif N%2==0 and N//2 %2==1:
    for k in range (0,N//4):
        B.append(A[N-2*k-1])
        B.append(A[2*k+1])
    B.append(A[N//2])
    B.append(A[N//2-1])
    for i in range (0,N//4):
        B.append(A[N//2+2*i+1])
        B.append(A[N//2-2*i-3])
    print(*B)