import sys

lucky = str(input())
position = 0
multiplicador=1
for char in lucky[::-1]:
    if char == '4':
        position+=multiplicador*1
    else:
        position+=multiplicador*2
    multiplicador*=2

print (position)
