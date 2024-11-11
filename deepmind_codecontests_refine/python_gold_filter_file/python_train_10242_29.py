def flip(i,j):
    if arr[i][j]==1:
        arr[i][j]=0
    else:
        arr[i][j]=1
        
global arr
arr=[]
for n in range(3):
    a,b,c=1,1,1
    arr.append([a,b,c])

myarray=[]
for i in range(3):
    temp=[int(x)%2 for x in input().split()]
    myarray.append(temp)
    
for i in range(len(myarray)):
    for j in range(len(myarray[i])):
        if myarray[i][j]==1:
            flip(i,j)        
            if i-1>=0:
                flip(i-1,j)
            if i+1<=2:
                flip(i+1,j)
            if j+1<=2:
                flip(i,j+1)
            if j-1>=0:
                flip(i,j-1)            

for p in range(len(arr)):
    for q in range(len(arr[p])):
        print(arr[p][q],end="")
    print()