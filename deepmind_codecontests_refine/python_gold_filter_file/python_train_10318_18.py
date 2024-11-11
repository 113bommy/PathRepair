n = int(input())
c = [0] * 101
a = [int(i) for i in input().split()]
for i in range(n):
    c[a[i]] += 1
if n == c.count(1) + c.count(2) * 2:
    if c.count(1) % 2 == 1:
        print("NO")
    else:
        print("YES")
        k = c.count(1) // 2
        for i in range(n):
            if c[a[i]] == 1:
                if k:
                    k -= 1
                    print("A", end = "")
                else:
                    print("B", end = "")
            else:
                print("A", end = "")
else:
    print("YES")
    if c.count(1) % 2 == 0:
        k = c.count(1) // 2
        for i in range(n):
            if c[a[i]] == 1:
                if k:
                    k -= 1
                    print("A", end = "")
                else:
                    print("B", end = "")
            else:
                print("A", end = "")
    else:
        d = 0
        k = c.count(1) // 2
        for i in range(n):
            if c[a[i]] == 1:
                if k:
                    k -= 1
                    print("A", end = "")
                else:
                    print("B", end = "")
            elif not d and c[a[i]] > 2:
                print("A", end = "")
                d = 1
            else:
                print("B", end = "")
            
