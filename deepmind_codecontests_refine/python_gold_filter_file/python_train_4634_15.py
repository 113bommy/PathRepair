s=input()
x='h','e','l','o'
s=s.lower()
h=s.find('h')
e=s.find('e',h)
l=s.find('l',e)
l2=s.find('l',l+1)
o=s.find('o',l2)
if h<e<l<l2<o:
    print('YES')
else:
    print('NO')
#print(h,e,l,l2,o)