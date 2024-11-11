# cook your dish here
s=list(input().split())
if(s[2]=="week"):
    if(s[0]=='5' or s[0]=='6'):
        print(53)
    else:
        print(52)
if(s[2]=="month"):
    if(s[0]=='31'):
        print(7)
    elif(s[0]=='30'):
        print(11)
    else:
        print(12)