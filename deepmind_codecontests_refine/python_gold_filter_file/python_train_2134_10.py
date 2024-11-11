n, m = [int(x) for x in input().split()]
n, m = sorted([n, m])
x1, y1 = [int(x) for x in input().split()]
x2, y2 = [int(x) for x in input().split()]
if (y1 + y2 <= m) and (max(x1, x2) <= n):
    print("YES")
elif (max(y1, y2) <= m) and (x1 + x2 <= n):
    print("YES")
elif (y1 + x2 <= m) and (max(x1, y2) <= n):
    print("YES")
elif (max(y1, x2) <= m) and (x1 + y2 <= n):
    print("YES")
elif (x1 + y2 <= m) and (max(y1, x2) <= n):
    print("YES")
elif (max(x1, y2) <= m) and (y1 + x2 <= n):
    print("YES")
elif (y1 + y2 <= n) and (max(x1, x2) <= m):
    print("YES")
elif (max(y1, y2) <= n) and (x1 + x2 <= m):
    print("YES")
else:
    #print(x1+x2, y1+y2)
    #print(x1+y2, y1+x2)
    print("NO")