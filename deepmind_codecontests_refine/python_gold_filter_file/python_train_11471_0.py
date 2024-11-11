
q = int(input())

for _ in range(q):
    n = 4*int(input())
    arr = [int(x) for x in input().split()]
    arr.sort()
    
    works = True
    area = arr[0]*arr[-1]
    for i in range(0,n//2,2):
        if arr[i] != arr[i+1] or arr[n-i-1] != arr[n-i-2]:
            works = False
        if arr[i]*arr[n-i-1] != area:
            works = False
    print("YES" if works else "NO")

