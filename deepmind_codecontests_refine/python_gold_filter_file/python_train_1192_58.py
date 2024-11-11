s= input()
w = input()
l1 = "qwertyuiop"
l2 = "asdfghjkl;"
l3 = "zxcvbnm,./"
res = ""
if s =="R":
    for i in w:
        if i in l1:
            res += l1[l1.index(i)-1]
        elif i in l2:
            res += l2[l2.index(i)-1]
        elif i in l3:
            res += l3[l3.index(i)-1]
else:
    for i in w:
        if i in l1:
            res += l1[l1.index(i)+1]
        elif i in l2:
            res += l2[l2.index(i)+1]
        elif i in l3:
            res += l3[l3.index(i)+1]
print(res)