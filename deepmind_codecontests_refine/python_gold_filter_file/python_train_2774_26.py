
x=input()
x=x.split(" ")
h=int(x[0])
n=int(x[1])
arr=[]
arr=input()
arr=arr.split(" ")
best=(1,h%(int (arr[0])))

for i in range(n):
    val=int (arr[i])
    x=h%val
    if (x < best[1]):
        best=(i+1,x)
print (best[0],int (h//int(arr[best[0]-1])))
