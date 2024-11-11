n , k , a , b = map(int, input().split())
n1 = n
if a + b < n:
    print("NO")
    exit()
res = ""
imposa, imposb = False, False
while n1 > 0 and a >= 0 and b >=0:
    if a > b:
        if imposa:
            if b <= 0:
                print("NO")
                exit()
            res += "B"
            imposa = False
            b -= 1
            n1 -= 1
        else:
            if min(k, a - b) == k:
                imposa = True
            res += "G" * min(k,a - b)
            n1 -= min(k, a - b)
            a -= min(k,a - b)
    elif b > a:
        if imposb:
            if a <= 0:
                print("NO")
                exit()
            res += "G"
            imposb = False
            a -= 1
            n1 -= 1
        else:
            if min(k, b - a) == k:
                imposb = True
            res += "B" * min(b - a,k)
            n1 -= min(k, b - a)
            b -= min(k, b - a)
    else:
        if res and res[-1] == "B":
            res += "GB" * (n1 // 2)
        elif res and res[-1] == "G":
            res += "BG" * (n1 // 2)
        else:
            res += "GB" * (n1 // 2)
        n1 = 0
print(res)
        
