def solve(a, b, k, arr1, arr2):
    num1 = [0 for i in range(a)]
    num2 = [0 for i in range(b)]
    for i in range(k):
        num1[arr1[i]-1] += 1
        num2[arr2[i]-1] += 1
    ans = k * k
    for x in num1:
        ans -= x * x
    ans //= 2
    for x in num2:
        ans -= x * (x-1) // 2
    return ans
        

t = int(input())
for i in range(t):
    a, b, k = map(int, input().split())
    arr1 = list(map(int, input().split()))
    arr2 = list(map(int, input().split()))
    print(solve(a, b, k, arr1, arr2))
    
