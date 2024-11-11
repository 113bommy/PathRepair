n, k = list(map(int, input().split()))
arr = list(map(int, input().split()))
arr.sort()
arr = arr[n//2:]
mid = arr[0]
start = mid
end = mid+k
 
while(start<end):
    op = k
    f=0
    med = (end+start+1)//2
    for i in range(len(arr)):
        if arr[i] < med:
            op-=med-arr[i]
        if op <0:
            f = 1
            break
    if f==1:
        end = med-1
    else:
        start = med
 
print(start)
