for t in range(int(input())):
    n = int(input())
    A = list(map(int, input().split()))
    B = []
    for i in range(0,n,2):
        x = 1
        if A[i] > A[i+1]:
            if A[i] % A[i+1] != 0:
                x =A[i+1]
            B.append(x)
            B.append(-((A[i]*x)//A[i+1]))
        else:
            if A[i+1] % A[i] != 0:
                x = A[i]
            B.append(-((A[i+1]*x)//A[i]))
            B.append(x)
    print(*B)
