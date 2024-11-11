a=input()
if (a[0]=="a" or a[0]=="h") and (a[1]=="1" or a[1]=="8"):
    print(3)
elif (a[0]=="a" or a[0]=="h") and (a[1]!="1" and a[1]!="8"):
    print(5)
elif (a[0]!="a" and a[0]!="h") and (a[1]=="1" or a[1]=="8"):
    print(5)
else:
    print(8)