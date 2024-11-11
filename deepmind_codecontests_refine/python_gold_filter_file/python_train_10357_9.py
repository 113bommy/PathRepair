a=['zero','one','two','three','four','five','six','seven','eight','nine','ten']
b=['eleven','twelve','thirteen','fourteen','fifteen','sixteen','seventeen','eighteen','nineteen','twenty']
c=['twenty','thirty','forty','fifty','sixty','seventy','eighty','ninety']
n=input()
z=int(n)
if z<=10:
    print(a[z])
elif z<=20:
    print(b[z-11])
else:
    if n[1]=='0':
        print(c[int(n[0])-2])
    else:
        x=''
        x=x+(c[int(n[0])-2])
        x=x+'-'
        x=x+a[int(n[1])]
        print(x)
