a=input()
c=0
for i in a:
    if i in ["a","e","i","o","u"]:
        c+=1

    elif "0"<=i<="9":
        if i not in ["0","2","4","6","8"]:

            c+=1
print(c)