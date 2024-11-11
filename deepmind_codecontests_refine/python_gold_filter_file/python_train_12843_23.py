def solve(a):
    count = 0 
    while a != 0:
        temp = a%10
        a = a//10
        if temp == 4 or temp == 7:
            count += 1
    return count
n,k = map(int,input().split())
arr = list(map(int,input().split()))
count = 0
for i in arr:
    c = solve(i)
    if c <= k:
        count += 1
print(count)
