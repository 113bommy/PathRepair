n = int(input())
a = [int(i) for i in input().split()]
if (n > 1 and a.count(0) != 1) or (n == 1 and a[0] == 0):
    print("NO")
else:
    print("YES")
