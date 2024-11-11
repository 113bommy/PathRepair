'''Author:  Abdurasul !!!'''

a=['zero','one','two','three','four','five','six','seven','eight','nine','ten','eleven','twelve','thirteen','fourteen','fifteen','sixteen','seventeen','eighteen','nineteen','twenty']
b=['','ten','twenty','thirty','forty','fifty','sixty','seventy','eighty','ninety']
n=input()
if int(n)<=20:print(a[int(n)])
else:
    if n[1]=='0':print(b[int(n[0])])
    else:print(b[int(n[0])]+'-'+a[int(n[1])])
