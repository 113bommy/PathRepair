s=input()
t=input()
for i in range(len(s)):
    if s==t[i:]+t[:i]:print("Yes");exit()
print("No")