n = int( input())
arr = [] 
for _ in range(n):
    ar = [int(num) for num in input().split()]
    ar = [k for k in range(ar[0], ar[1] + 1)] 
    arr.append(ar)
m = int(input())
for ar in arr:
    if m in ar:
        print(n - arr.index(ar))
        break