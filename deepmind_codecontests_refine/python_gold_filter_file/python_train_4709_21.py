x= input()
if x.upper()==x:
    print( x.lower())
elif x[0].lower()==x[0] and x[1:].upper()==x[1:]:
    print(x[0].upper()+x[1:].lower())
else:
    print(x)