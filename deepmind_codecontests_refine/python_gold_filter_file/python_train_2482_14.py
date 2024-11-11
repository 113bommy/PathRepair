s = input()
t = input()
S = "UNRESTORABLE"
for i in range(len(s)-len(t), -1, -1):
    flag = all([s[i+j] == t[j] or s[i+j] == "?" for j in range(len(t))])
    if flag:
        S = s[:i]+t+s[i+len(t):]
        S = S.replace("?", "a")
        break
print(S)