def fil(a):
    if a.isalpha and a!=" ":
        return True
    else:
        return False

a = input()
line= [l for l in a]
line = list(filter(fil, line))
if line[-2] in "aeiouyAEIOUY":
    print("YES")
else:
    print("NO") 