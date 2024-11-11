n=int(input())
l1=[int(x) for x in input().split()]
l2=[int(x) for x in input().split()]
if sum(l1)>=sum(l2):
    print("Yes")
else:
    print("No")