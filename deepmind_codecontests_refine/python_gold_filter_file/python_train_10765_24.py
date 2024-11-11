n=(input())
n=n[::-1]
a=[]
a.append("O-|-OOOO")
a.append("O-|O-OOO")
a.append("O-|OO-OO")
a.append("O-|OOO-O")
a.append("O-|OOOO-")
a.append("-O|-OOOO")
a.append("-O|O-OOO")
a.append("-O|OO-OO")
a.append("-O|OOO-O")
a.append("-O|OOOO-")
for i in n:
    print(a[int(i)])