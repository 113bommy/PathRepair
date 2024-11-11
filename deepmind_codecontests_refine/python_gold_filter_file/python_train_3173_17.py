import sys
n,k=[int(x) for x in sys.stdin.readline().strip().split()]
arr=[int(x) for x in sys.stdin.readline().strip().split()]
if max(arr)-min(arr)>k: print("NO")
else:
    print("YES")
    for i in arr:
        for j in range(i): print(j%k+1,end=" ")
        print("")
