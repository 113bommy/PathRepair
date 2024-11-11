from collections import Counter
for _ in range(int(input())):
    n = int(input())
    arr = list(map(int,input().split()))
    arr.sort()
    dic = Counter(arr)
    res  = 0
    for s in range(2,2*n +1):
        total = 0 
        for j in dic:
            if j>s//2:
                # print(s,j)
                pass
            else:
                if j==s/2:
                    total+=dic[j]//2
                else:
                    total+= min(dic[j], dic[s-j])
            # print(s,j,dic[j],dic[s-j], total)
        res = max(res,total)
    print(res)



