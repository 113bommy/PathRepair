def find(A):
    n,m,k=A
    if m<k:
        return 1
    
    temp1=1
    temp2=1
    for i in range(k+1):
        temp1*=(m-i)
        temp2*=(n+i+1)
    return max(1-temp1/temp2,0)
print(find(list(map(int,input().strip().split(' ')))))
