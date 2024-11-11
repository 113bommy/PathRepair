def check(L) :
    L.sort()
    return L[1]+L[2] == L[0]*4 and L[0]*3 == L[3]

n = int(input())
A = []
for i in range(n) :
    A += [int(input())]

A.sort()

if n == 0 :
    print("YES", 1, 1, 3, 3, sep='\n')
elif n == 1 :
    print("YES", 2*A[0], 2*A[0], 3*A[0], sep='\n')
elif n == 2 :
    if A[0] * 3 == A[1] :
        print("YES", 2*A[0], 2*A[0], sep='\n')
    elif A[0] * 3 > A[1] :
        print("YES", A[0] * 4 - A[1], A[0] * 3, sep='\n')
    else :
        print("NO")
elif n == 3 :
    if A[0] * 4 == A[1] + A[2] :
        print("YES", A[0] * 3, sep='\n')
    elif A[0] * 3 == A[2] :
        print("YES", A[0] * 4 - A[1], sep = '\n')
    elif A[2] % 3 == 0 and A[2] // 3 * 4 == A[0] + A[1] :
        print("YES", A[2] // 3, sep = '\n')
    else :
        print("NO")
elif n == 4 :
    if check(A) : print("YES")
    else : print("NO")
