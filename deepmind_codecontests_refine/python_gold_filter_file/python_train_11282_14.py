s = input()
s2 = input()
step = 0
for i in range(len(s2)):
    if s2[i] == s[step]:
        step+=1

print(step+1)
