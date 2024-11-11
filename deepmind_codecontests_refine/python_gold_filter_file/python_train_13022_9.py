n,m=map(int,input().split())
arr=[]
for i in range(n):
    arr1=list(map(int,input().split()))
    arr.append(arr1)
arrx=[]
for i in range(1,m+1):
    flag=0
    for j in range(n):
        if(i>=arr[j][0] and i<=arr[j][1]):
            flag=1
            break
    if(flag==0):
        arrx.append(i)
print(len(arrx))
print(*arrx)
