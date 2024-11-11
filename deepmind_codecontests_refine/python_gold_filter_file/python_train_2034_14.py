x=  int (input())
if x<= 127 :
    print ('byte')
elif x<=32767 :
    print ('short')
elif x<= 2147483647 :
    print ('int')
elif x<= 9223372036854775807:
    print ('long')
else :
    print ('BigInteger')
