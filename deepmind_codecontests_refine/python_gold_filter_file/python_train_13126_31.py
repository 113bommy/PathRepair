n = int(input())
l1 = list(input().strip().split(" "))
l1 = [int(x) for x in l1]
l2 = list(input().strip().split(" "))
l2 = [int(x) for x in l2]
if sum(l2) > sum(l1) :
    print("No")
else:
    print("Yes")