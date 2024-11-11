def s(g):
    g=str(g)
    k=list(g)
    if '8' in k:
        return False
    return True
mode="fiadasdle"
if mode=="file":f=open("test.txt","r")

if mode=="file":n=int(f.readline())
else:n=int(input())
b=n+1
while s(b):b+=1
print(b-n)

if mode=="file":f.close()
