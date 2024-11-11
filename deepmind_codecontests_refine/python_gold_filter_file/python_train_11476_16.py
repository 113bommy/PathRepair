def process(A, m):
    A = sorted(A)
    answer = 1
    n = len(A)
    if n-10 <= m:
        for i in range(n):
            for j in range(i+1, n):
                answer = answer*(A[j]-A[i])
                answer = answer % m
                if answer==0:
                    return 0
        return answer
    else:
        return 0

n, m = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
print(process(A, m))