s=input()
t=input()
f=0
for i in range(len(s)):
    if s[i]!=t[i]:
        f+=1
print(f)