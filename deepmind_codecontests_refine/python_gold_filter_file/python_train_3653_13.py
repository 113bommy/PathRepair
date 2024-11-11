
entrada = input()
entrada = entrada.split(' ')

a = int(entrada[0]) # zeroes
b = int(entrada[1]) # ones
x = int(entrada[2]) # x = |s|, s = forall(ai != ai+1)

"""
1 <= a, b <= 100, 1 <= 1 < a+b

2 2 1
1100
______________
0011

3 3 3
101100
______________
001011

5 3 6
01010100
______________
0101010
"""

string = ""
if a >= b:
    last = 0
    string += '0'
    a -= 1
    while x > 0:
        
        if last == 0:
            b -= 1
        else:    
            a -= 1
        
        last = ( last + 1 ) % 2
        string += str( last )
        x -= 1

    string = string[0] + a*'0' + string[1:len(string)]
    string = string[0:a+1] + b*'1' + string[a+1:len(string)]
else:
    last = 1
    string += '1'
    b -= 1
    while x > 0:
        
        if last == 0:
            b -= 1
        else:
            a -= 1

        last = ( last + 1 ) % 2
        string += str( last )
        x -= 1
    
    string = string[0] + b*'1' + string[1:len(string)]
    string = string[0:b+1] + a*'0' + string[b+1:len(string)]

print(string)