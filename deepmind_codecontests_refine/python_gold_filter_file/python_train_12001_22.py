#print("Codeforces 673 Div2 A ")
t = int(input())
while(t>0):
    n,k = map(int,input().split())
    arr = list(map(int,input().strip().split()))[:n]
    arr.sort()
    ans = 0
    for i in range(1,n,+1):
        if arr[i] >= k:
            continue
        else:
            ans = ans + (k-arr[i])//arr[0]
    print(ans)
    t-=1
