# Code by : Sam._.072

for _ in range(int(input())):
    s=input()
    x=s.count('ab')
    y=s.count('ba')
    # print(x,y)
    if x==y:
        print(s)
    elif x>y:
        i=0
        z=""
        while i <len(s):
            if x>y and s[i]=='a':
                z+='b'
                i+=1
                x-=1
            else:
                z+=s[i]
                i+=1
        print(z)
    else:
        i=0
        z=""
        while i<len(s):
            if y>x and s[i]=='b':
                z+='a'
                i+=1
                y-=1
            else:
                z+=s[i]
                i+=1
        print(z)

    