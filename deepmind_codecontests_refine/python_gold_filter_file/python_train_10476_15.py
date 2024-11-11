s = input()
cou = 0
pre = 0
for i in range(len(s)):
    if s[i] == "Q":
        pre += 1
    if s[i] == "A":
        if pre > 0:
            flag_right = 0
            for k in range(i+1,len(s)):
                if s[k] == "Q":
                    flag_right += 1
            if flag_right > 0:
                cou +=(pre*flag_right)
print(cou)
