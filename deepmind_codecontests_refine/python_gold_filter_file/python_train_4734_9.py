s=str(input())
s=s.replace('?','')
s=s.replace(' ','')
d=s[len(s)-1]
if(d in 'aeiouy' or d in 'AEIUOY'):
    print('YES')
else:
    print("NO")