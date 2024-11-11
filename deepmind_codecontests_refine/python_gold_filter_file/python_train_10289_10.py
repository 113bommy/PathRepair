s=input()
if len(s)<26:
    al=[chr(ord('a') + i) for i in range(26)]
    for i in al:
        if not(i in s):
            print(s+i)
            exit()
if s=="zyxwvutsrqponmlkjihgfedcba":
    print(-1)
    exit()
a=[]
for i in range(25,-1,-1):
    for j in range(24-(25-i),-1,-1):
        if s[j]<s[i]:
            a.append(s[:j]+s[i])
print(min(a))