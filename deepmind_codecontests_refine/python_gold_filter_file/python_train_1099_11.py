a=[8,4,2,6]
x=int(input())
if x==0:
    print(1)
else:
    print(a[x%4-1])
