n = input()
x = input()

y = n[0]
z = n[1]

l = x.split()

a = l[0]
b = l[1]
c = l[2]
d = l[3]
e = l[4]

if y in a or y in b or y in c or y in d or y in e:
    print("Yes")
elif z in a or z in b or z in c or z in d or z in e:
    print("Yes")
else:
    print("No")
