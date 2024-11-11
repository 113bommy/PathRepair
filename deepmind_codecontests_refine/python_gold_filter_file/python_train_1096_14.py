n = int(input())
arr = [int(x) for x in input().split()]
aaa = []
for i in range(n):
    if(arr[i]==1):
        aaa.append(i)
    elif(arr[i]==n):
        aaa.append(i)

a = aaa[0]
b = n-1-aaa[1]
if(a>b):
    print(n-b-1)
else:
    print(n-a-1)