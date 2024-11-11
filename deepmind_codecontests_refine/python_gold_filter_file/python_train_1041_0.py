import bisect
n = int(input())
A = []
for i in range(n):
    num  = int(input())
    if A == []:
        A.append(num)
    elif num > A[-1]:
        A.append(num)
    else:
        j = bisect.bisect_left(A, num)
        A[j] = num
print(len(A))