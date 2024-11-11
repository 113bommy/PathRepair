n=(int(input()))
a=list(map(int,input().split()))
b=list(map(int,input().split()))
aS=sum(a)
bsort=b.sort(reverse=True)
bS=b[0]+b[1]

if aS<=bS:
    print("YES")
else:
    print("NO")