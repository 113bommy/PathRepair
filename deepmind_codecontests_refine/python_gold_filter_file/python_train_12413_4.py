from collections import Counter
t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int,input().split()))
    counts = sorted(list(dict(Counter(arr)).items()),key = lambda x:x[1])
    size = len(counts)

    if size<=1:
        if counts[0][1]>=2:
            print(1)
        else:
            print(0)
        continue
    ans = 0
    ans = min(size-1,counts[-1][1])
    if counts[-1][1]>size:
        ans+=1
    print(ans)
