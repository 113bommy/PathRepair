import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n,k = list(map(int,input().split()))
    arr = list(map(int,input().split()))
    sindex = 0
    endindex = len(arr)-1
    ans = 0
    while endindex>=sindex:
        endindex-=n//2
        ans+=arr[endindex]
        endindex-=1
        sindex+=(n-1)//2
    print(ans)