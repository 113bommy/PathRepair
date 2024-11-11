s = input().strip()
n = len(s)
fl = False
for a in range(1, 6):
    for b in range(1, 21):
        if (fl):
            break
        k = a * b - n
        if (k < 0):
            continue
        x = (k + a - 1) // a
        y = x * a - k
        i = 0
        ans = [['*'] * b for j in range(a)]
        for i_ in range(a):
            for j_ in range(b - x):
                if (i == n):
                    break      
                ans[i_][j_] = s[i]
                i += 1
                if (i < n and i_ < y and j_ == b - x - 1):
                    ans[i_][j_ + 1] = s[i]
                    i += 1                    
        print(a, b)
        for i in range(a):
            print(*ans[i], sep = '')
        fl = True
        