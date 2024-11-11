ch=input()
if (ch[0]=='a' or ch[0]=='h') and (ch[1]=='8' or ch[1]=='1'):
    print(3)
elif (ch[0] in ['a','b','c','d','e','f','g','h']) and( ch[1] in ['1','8'] ):
    print(5)
elif (ch[0] in ['a','h']) and (ch[1] in ['1' ,'2','3','4','5','6','7','8']):
    print(5)
else :
    print(8)
