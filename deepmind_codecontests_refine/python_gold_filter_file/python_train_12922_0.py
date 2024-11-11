n=int(input())
a= list(map(int, input().split()))

a.sort()
l=len(a)

x= a[l-2] - a[0]
y=a[l-1]-a[1]

if x<y:
    print(x)

else:
    print(y)
