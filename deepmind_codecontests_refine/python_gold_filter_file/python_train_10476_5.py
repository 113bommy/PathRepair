'''
instagram : essipoortahmasb2018
channel Telegram : essi_python
'''
c = 0
s = input()
t = ""
for i in s:
    if i in ("AQ"):
        t+=i

for i in range(len(t)):
    if t[i]=='Q':
        for j in range(i+1,len(t)-1):
            if t[j]=='A':
                c+=t[j+1:].count('Q')
                
print(c)