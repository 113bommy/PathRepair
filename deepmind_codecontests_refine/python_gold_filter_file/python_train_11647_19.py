s = input()
for i in range(1,len(s)):
    if s[i] == s[i-1]:
        print(i, i+1)
        exit()

for i in range(2,len(s)):
    if s[i]==s[i-2]:
        print(i-1, i+1)
        exit()

print("-1 -1")
