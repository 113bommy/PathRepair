s=input()
s="".join(s.split('>'))
s="".join(s.split('<'))
a=[]
i=0
tab=0
ws=' '
while i<len(s):
    if s[i]!='/':
        a.append(ws*tab+'<'+s[i]+'>')
        tab+=2
        i+=1
    if s[i]=='/':
        tab-=2
        a.append(ws*tab+'</'+s[i+1]+'>')
        i+=2
        
for i in a:
    print(i)
    
