R = lambda: list(map(int, input().split()))
n = R()
A = R()
B = sorted(A)

l = 0
r = 0
isOk = True
idx = []
if A == B:
    print('yes')
    print('1 1')
else:
    for i in range(len(A)):
        if A[i] != B[i]:
            l = i
            break
    for i in range(len(A)):
        if A[i] != B[i]:
            r = i + 1
        else:
            idx.append(A[i])
    A[l:r] = A[l:r][::-1]
    if A == B:
        print('yes')
        
        print(l+1,r)
    else:
        print('no')

