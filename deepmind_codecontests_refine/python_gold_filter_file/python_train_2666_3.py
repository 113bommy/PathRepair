n= int (input())
ch=input()
l=[]
i = 0
k=0

while (i<len(ch)):
    if (ch[i].isupper()):
        k=k+1
    if (ch[i]==' '):
        l.append(k)
        k=0
    i+=1
l.append(k)
v=max(l)
print (v)
