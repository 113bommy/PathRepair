string=input()
l1=string.split(" ")
l1=list(map(int,l1))
l1.sort()

x1=int(l1[0])
x2=int(l1[1])
x3=int(l1[2])


d=x3-x2
d+=x2-x1
print(d)