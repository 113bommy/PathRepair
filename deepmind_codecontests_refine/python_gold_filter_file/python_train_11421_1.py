s=input()
if len(set(s))==1:
    print("0")
elif s!=s[ ::-1]:
    print(len(s))
else:
    print(len(s)-1)
