n=int(input())
li=list(map(int,input().split()))
li.sort()
if li[n-1]!=li[n]:
    print("YES")
else:
    print("NO")
