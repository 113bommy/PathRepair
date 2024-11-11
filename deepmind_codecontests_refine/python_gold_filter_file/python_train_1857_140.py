N=int(input())
a=sorted([int(i) for i in input().split()],reverse=True)
print(sum(a[0::2])-sum(a[1::2]))
