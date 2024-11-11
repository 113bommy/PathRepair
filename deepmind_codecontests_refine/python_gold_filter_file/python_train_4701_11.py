n = int(input())
s = list(input())
a = s.count('(')
b = 0

for i in range(len(s)):
    if s[i]=='?':
        if a<n//2:
            s[i] = '('
            a+=1
        else:
            s[i] = ')'
    
    b+= 1 if s[i]=='(' else -1
    if b<=0 and i!=n-1:
        print(':(')
        raise SystemExit
        

print(':(' if b!=0 else ''.join(s))