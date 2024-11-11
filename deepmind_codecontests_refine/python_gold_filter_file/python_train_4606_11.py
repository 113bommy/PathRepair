"""input
5

"""
def digit(n):
    return len(str(n))
def convert(a, b):
    c = ""
    while a>0:
        if(a%b>=10):
            c+=chr(55+(a%b))
        else:
            c += str(a%b)
        a = a//b
    return c[::-1]
def number(a, b):
    i = digit(a)
    a = str(a)
    c= a[::-1]
    l = 0
    for t in range(i):
        l+= (b**(t))*int(c[t])
    return l
x=convert(int(input()),2)
n=len(x)
if(n<6):
	x='0'*(6-n)+x
# print(x)
x=list(x)
x[1],x[5]=x[5],x[1]
x[2],x[3]=x[3],x[2]
print(number(''.join(x),2))