a=input()[1:-1].replace(" ", "").split(",")
if a[0]=="":
    print("0")
else:
    print(len(set(a)))