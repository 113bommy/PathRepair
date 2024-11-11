s = input()
ans = 'YES'
i = 97
while i < 123 and len(s)>0:
    if chr(i)==s[0]:
        s = s.replace(chr(i),'')
    else:
        ans = 'NO'
        break
    i = i + 1
print(ans)