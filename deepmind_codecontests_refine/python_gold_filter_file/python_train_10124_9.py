import sys 
def findCloset(A, B, C, p, q, r): 
    diff = sys.maxsize 

    res_i = 0
    res_j = 0
    res_k = 0

    i = 0
    j = 0
    k = 0
    while(i < p and j < q and k < r): 

        minimum = min(A[i], min(B[j], C[k])) 
        maximum = max(A[i], max(B[j], C[k])); 
        if maximum-minimum < diff: 
            res_i = i 
            res_j = j 
            res_k = k 
            diff = maximum - minimum; 

        if diff == 0: 
            break

        if A[i] == minimum: 
            i = i+1
        elif B[j] == minimum: 
            j = j+1
        else: 
            k = k+1

    arr = [A[res_i],B[res_j],C[res_k]]
    arr.sort()
    return max(arr)-min(arr)



t= int(input())
while(t>0):
    s = list(input())
    a1 = []
    a2 = []
    a3 = []
    for i in range(len(s)):
        if s[i]=='1':
            a1.append(i)
        elif s[i]=='2':
            a2.append(i)
        else:
            a3.append(i)
    n1= len(a1)
    n2 = len(a2)
    n3 = len(a3)
    if n1==0 or n2==0 or n3==0:
        print(0)
    else:
        ans = findCloset(a1,a2,a3,n1,n2,n3)
        print(ans+1)
    t-=1