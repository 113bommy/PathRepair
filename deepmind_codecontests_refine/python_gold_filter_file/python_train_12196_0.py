def mystery(n):
    if n == 0:
        return 15
    
    #Find the binary rep.
    s = bin(n)[2:]
    diff = 4 - len(s)
    s = '0'*diff + s
    #print(s)
    #Reverse the binary number
    s = s[::-1]
    #print('Reverse: {}'.format(s))
    #Decrement the number
    val = int(s,2) - 1
    #print('Decremnt: {}'.format(val))
    #Reverse the number
    s = bin(val)[2:]
    diff = 4 - len(s)
    s = '0'*diff + s
    s = s[::-1]
    #print('Reverse again: {}'.format(s))
    #Convert to decimal and print
    return int(s,2)

n = int(input())
print(mystery(n))
