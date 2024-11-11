a = input()
b = input()
c = input()
if a=='rock' and b=='rock' and c=='paper' :
    print ('S')
elif a=='rock' and b=='paper' and c=='rock' :
    print ('M')
elif a=='paper' and b=='rock' and c=='rock' :
    print ('F')
elif a=='paper' and b=='paper' and c=='scissors' :
    print ('S')
elif a=='paper' and b=='scissors' and c=='paper' :
    print ('M')
elif a=='scissors' and b=='paper' and c=='paper' :
    print ('F')
elif a=='scissors' and b=='scissors' and c=='rock' :
    print ('S')
elif a=='scissors' and b=='rock' and c=='scissors' :
    print ('M')
elif a=='rock' and b=='scissors' and c=='scissors' :
    print ('F')
else :
    print ('?')