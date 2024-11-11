def b_n(s):
    return int(s,2)
def n_b(n):
    p= str(bin(n).replace("0b",""))
    while len(p)<m:
        p="0"+p
    return p
    
t=int(input())
for w in range(t):
    nm=list(map(int,input().strip().split()))
    n=nm[0]
    m=nm[1]
    arr=[]
    for g in range(n):
        arr.append(str(input()))
    for i in range(n):
        arr[i]=b_n(arr[i])
    k1=(2**m)-n
    k=(k1-1)//2
    for i in sorted(arr):
        if i<=k:
            k+=1
    print(n_b(k))