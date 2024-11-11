s = input()
ss = [""] * len(s)
v = "RBYG"
r = {"R": 0, "G": 0, "B": 0, "Y": 0}
if len(s) >= 5:
    for i in list(v):
        j = 0
        
        while i != s[j]:
            j += 1
        t = j
        while j < len(s):
            ss[j] = i
            j += 4
        
        while t >= 0:
            ss[t] = i
            t -= 4
    
    for i in range(len(s)):
        if s[i] != ss[i] and s[i] == '!':
            r[ss[i]] = r[ss[i]] + 1
    
    for i in v:
        print(r[i], end=" ")
else:
    for i in v:
        if i not in s:
            print(1, end=" ")
        else:
            print(0, end=" ")
    
