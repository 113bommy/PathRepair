arr=[int(x) for x in input().split()]
arr.sort()
print(min(arr[1]+arr[0],sum(arr)//3))
