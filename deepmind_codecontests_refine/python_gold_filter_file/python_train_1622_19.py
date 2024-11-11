from collections import Counter
n = int(input())
arr = list(map(lambda x: int(x), input().split()))

if len(Counter(arr))==1 and 0 in Counter(arr):
    print("NO")
else: 
    if sum(arr)!=0:
        print("YES")
        print("1")
        res = [str(1),str(n)]
        print(" ".join(res))
    else: 
        su = 0
        for i in range(len(arr)):
            su+=arr[i]
            if su!=0:
                print("YES")
                res1= [str(1),str(i+1)]
                res2 = [str(i+2),str(n)]
                print("2")
                print(" ".join(res1))
                print(" ".join(res2))
                break
    