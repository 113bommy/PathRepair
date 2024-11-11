# n=int(input())
# n,k=map(int,input().split())
'''l=0
r=10**13
while l+1<r:
    mid=(l+r)//2
    val=(max(0,b_b*mid-b)*rb+max(0,b_s*mid-s)*rs+max(0,b_c*mid-b)*rc)
    if val>money:
        r=mid
    if val<=money:
        l=mid'''
# arr=list(map(int,input().split()))
# n=int(input())
# n,k=map(int,input().split())
# arr=list(map(int,input().split()))
from collections import Counter
n=int(input())

arr=sorted([(n-int(x),i) for i,x in enumerate(input().split())])
ls=[0]*n
s=Counter(arr[i][0] for i in range(n) )
#print(s)
if all([size%ele==0 for ele,size in s.items()]):
    var=arr[0][0]
    f = 1
    for i in range(n):
        ls[arr[i][1]] = f
        var -= 1
        if var == 0 and i < n - 1:
            var =arr[i + 1][0]
            f += 1
    print("Possible")
    print(*ls)

else:
    print("Impossible")
    exit()

