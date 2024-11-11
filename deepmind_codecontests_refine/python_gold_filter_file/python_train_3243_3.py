def mp():
    return map(int, input().split())

n, bb, aa = mp()
s = list(mp())

a = aa
b = bb
i = 0
while i < n and not(a < 0 or b < 0 or a == 0 and b == 0):
    if a == aa:
        a -= 1
    elif s[i] == 1 and b != 0:
        b -= 1
        a += 1
    elif s[i] == 1:
        a -= 1
    else:
        if a > 0:
            a -= 1
        else:
            b -= 1
        
    #print(a, b)
    i += 1
    
print(i)