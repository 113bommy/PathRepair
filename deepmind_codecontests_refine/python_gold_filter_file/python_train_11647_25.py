s=input()
for i in range(len(s)):
    if i>=1:
        if s[i]==s[i-1]:
            print(i, i+1)
            exit()
    if i>=2:
        if s[i]==s[i-2]:
            print(i-1, i+1)
            exit()
print(-1, -1)