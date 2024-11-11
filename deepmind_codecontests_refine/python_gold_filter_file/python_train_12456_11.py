n =  int(input())
arr1 = []
can = False
arr1 = list(map(int, input().split()))
arr = []
arr.append(0)
for i in range(0,n):
    arr.append(arr1[i])
for i in range(1,n+1):

    #print( arr[arr[arr[i]]], i)
    if arr[arr[arr[i]]] == i:
        can =  True
        break
if can == True:
    print("YES")
else:
    print("NO")
