

for i in range(0,int(input())):
    
    n,k =[int(t) for t in input().split()]
    temp=[int(t) for t in input().split()]
    arr=[]
    for i in temp:
        if i not in arr: arr.append(i)
    
    if len(arr)>k:
        print(-1)
        continue
    print(n*k)

    for i in range(0,n):
        for a in arr:
            print(a,end=' ')
        for j in range(0,k-len(arr)):
            print("1",end=' ')
    print("")








        






    







