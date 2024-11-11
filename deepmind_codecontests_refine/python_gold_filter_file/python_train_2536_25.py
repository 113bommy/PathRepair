s = input()


if s[:4] == 'http':
    ans = 'http://'
    b = 4
else:
    ans = 'ftp://'    
    b = 3
    
for a in range(b+1,len(s)):
    if s[a]=='r' and s[a+1]=='u' :
        ans += s[b:a]
        ans += '.'
        ans += 'ru'
        break
    
if a+1 == len(s)-1:
    print(ans)
else:
    ans += '/'
    ans += s[a+2:]
    print(ans)    
