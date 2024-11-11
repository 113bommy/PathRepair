s = input()
if s[:3] == 'ftp':
        if s[-2:] == 'ru':
                print(s[:3]+'://'+s[3:-2]+'.ru')
        else: print(s[:3]+'://'+s[3:s.find('ru',4)]+'.ru/'+s[s.find('ru',4)+2:])
else: 
        if s[-2:] == 'ru':
                print(s[:4]+'://'+s[4:-2]+'.ru')
        else: print(s[:4]+'://'+s[4:s.find('ru',5)]+'.ru/'+s[s.find('ru',5)+2:])
