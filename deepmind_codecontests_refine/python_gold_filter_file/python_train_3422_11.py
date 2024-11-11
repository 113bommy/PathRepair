
import string
import sys

def CaesarCipher():
    
    low=string.ascii_lowercase
    
    for cry in sys.stdin: 
        for i in range(1,27):
            
            dec=cry.translate(str.maketrans(low,low[i:]+low[:i]))
    
            if 'this' in dec or 'that' in dec or 'the' in dec:
                print(dec[:-1])
            
                
    
CaesarCipher()