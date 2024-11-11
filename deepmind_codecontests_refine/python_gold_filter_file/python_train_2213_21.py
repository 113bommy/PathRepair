# ":"
import math
n, m = [int(i) for i in input().split()]
x, k, y = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
start = 0
if m >= n:
    if m > n:
        print(-1)
    if m == n:
        if a == b:
            print(0)
        else:
            print(-1)
else:
    flag = 0
    points = []
    for i in range(n):
        if a[i] == b[start]:
            points.append(i)
            start += 1
            if start >= m:
                flag = 1
                start = m-1
    if len(points) != m:
        print(-1)
    else:
        if points[0] != 0:
            points.insert(0, -1)
        if points[-1] != (n - 1):
            points.append(n)
        # print(points)
        costs = [0] * n
        if flag == 0:
            print(-1)
        g_mi = flag1 = 0
        for i in range(len(points)-1):
            g_mi = flag1 = 0
            if (points[i+1] - points[i]) == 1:
                continue
            else:
                for j in range(points[i]+1, points[i+1]):
                    g_mi = max(g_mi, a[j])
                dist = (points[i+1] - 1) - (points[i]+1) + 1
                if x <= (k * y):
                    rem = dist % k
                    quo = dist // k
                    pend = -1
                    ans = (quo*x) + (rem * y)
                    if quo == 0:
                        pend = g_mi
                    if points[i] != -1 and points[i+1] != n:
                        if pend > a[points[i]] and pend > a[points[i+1]]:
                            flag1 = 1
                            break
                    else:
                        if points[i] == -1:
                            if pend > a[points[i + 1]]:
                                flag1 = 1
                                break
                        elif points[i+1] == n:
                            if pend > a[points[i]]:
                                flag1 = 1
                                break
                else:
                    pend = g_mi
                    t1 = t2 = pend - 1
                    if points[i] != -1:
                        t1 = a[points[i]]
                    if points[i+1] != n:
                        t2 = a[points[i+1]]
                    if pend > t1 and pend > t2:
                        if dist >= k:
                            ans = (x + (dist-k)*y)
                        else:
                            flag1 = 1
                            break
                    else:
                        ans = dist * y
                if flag1 == 1:
                    break
                costs[i] = ans
        if flag1 == 1:
            print(-1)
            #print(*costs)
        else:
            #if n == 200000 and m == 2:
                #print(*points)
                #print(costs[1],costs[2],costs[3])
            print(sum(costs))













