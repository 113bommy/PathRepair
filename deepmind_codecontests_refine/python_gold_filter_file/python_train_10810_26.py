s=input()
while 1:
    s=s[:-2]
    if s[:len(s)//2]==s[len(s)//2:]:
        break
print(len(s))