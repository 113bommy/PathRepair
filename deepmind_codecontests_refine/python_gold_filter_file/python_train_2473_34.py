le=int(input())

a=list(map(int,input().split()))

a=sorted(a)

main=(len(a)-1)//2

print(a[main])