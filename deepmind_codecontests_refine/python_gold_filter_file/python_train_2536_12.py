s = input()
if(s[0] == 'f'):
    fs = 'ftp://'
    s = s[3:]
else:
    fs = 'http://'
    s = s[4:]
for i in range(len(s)-1):
    if(s[i]+s[i+1] == 'ru'):
        j = i+1
        
fs = fs+s[0:j-1]+'.ru'
if(j != len(s)-1):
    fs = fs+'/'+s[j+1:]
print(fs)