

AX,AY = (int(x) for x in input().split(' '))
BX,BY = [int(x) for x in input().split(' ')]
CX,CY = [int(x) for x in input().split(' ')]

print(3)
print( str(AX+BX-CX)+' '+str(AY+BY-CY) )
print( str(AX-BX+CX)+' '+str(AY-BY+CY) )
print( str(BX-AX+CX)+' '+str(BY-AY+CY) )