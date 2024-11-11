curP = 0

input()

A = list(map(int, input().split()))

f= True
for i in range(1, len(A)):
    if A[i] > A[i-1] and (curP == 1 or curP == 2):
        f = False
        break
    
    elif A[i] == A[i-1] and (curP == 2): 
        f = False
        break
    
    elif A[i] == A[i-1]:
        curP = 1
    
    elif A[i] < A[i-1]:
        curP = 2
    
if f:
    print("YES")
else:
    print("NO")
        