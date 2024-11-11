n=int(input())
L1=[int(x) for x in input().split()]
L2=[int(x) for x in input().split()]
if sum(L2)<=sum(L1):
    print("Yes")
else:
    print("No")