t = int(input())
from collections import Counter
for _ in range(t):
    n,k = map(int,input().split())
    arr2 = list(map(int,input().strip().split()))[:n]
    arr1 = list(map(int,input().strip().split()))[:k]


    arr1.sort(reverse = True);arr2.sort()
    ans = 0;i=0
    for num in arr1[::-1]:
        if num == 1:
            ans+=(arr2[-1]*2)
            arr2.pop()
        else:
            ans+=arr2[-1]
            arr2.pop()

    for num in arr1:
        if num == 1:
            continue
        else:
            ans += arr2[i]

            i+= (num-1)

    print(ans)
