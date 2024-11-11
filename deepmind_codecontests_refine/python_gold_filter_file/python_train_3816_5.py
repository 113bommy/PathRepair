r, c = map(int, input().split())
a = []
tr = True
сount = 0
for i in range(r):
    s = input().replace(".", "D")
    if "SW" in s or "WS" in s:
        tr = False
    #if "S" not in s:
    #    сount += 1
    a.append(s)

if not(tr) or сount == r:
    print("No")
else:        
    for i in range(r):
        for j in range(c):
            if i > 0:
                if set(a[i][j]+a[i-1][j]) == {"W", "S"}:
                    tr = False
            if i < r-1:
                if set(a[i][j]+a[i+1][j]) == {"W", "S"}:
                    tr = False
    if tr:
        print("Yes")
        for i in a:
            print(i)
    else:
        print("No")
