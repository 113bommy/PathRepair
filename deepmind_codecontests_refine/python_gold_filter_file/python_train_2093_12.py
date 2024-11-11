def isdiv(arr, i):
    it = 0
    su = 0
    while(it < len(arr)):
        su+= arr[it]
        if su>i:
            return False
        if su==i:
            su = 0
        it += 1
    return True

l = int(input())
arr = list(map(int, list(input())))
divisible = False
total = sum(arr)
for i in range(1,int(total/2)+1):
    if (total%i == 0):
        divisible = isdiv(arr, i)
        if divisible:
            break
if (divisible) or (all([v == 0 for v in arr])):
    print("YES")
else:
    print("NO")
