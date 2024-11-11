n = int(input())
arr = list(map(int, input().split()))
arr.append(arr[0])
d=1000000
i1=0
for i in range(n):
    if abs(arr[i]-arr[i+1])<d:
        i1 = i
        d = abs(arr[i]-arr[i+1])
if i1 == n-1:
    print(n,1)
else:
    print(i1+1,i1+2)
    