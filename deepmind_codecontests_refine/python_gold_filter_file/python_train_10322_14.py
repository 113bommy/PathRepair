n = int(input())
arr = input().split(' ')
arr = [int(i) for i in arr]
v1 = len(arr) - 1 - arr[::-1].index(0)
v2 = len(arr) - 1 - arr[::-1].index(1)
print(min(v1,v2)+1)