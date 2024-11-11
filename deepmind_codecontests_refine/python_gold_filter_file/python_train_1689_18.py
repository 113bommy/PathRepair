import sys 

def getMultiLineInput() -> []:
    lines = []
    while True:
        try:
            lines.append(input())
        except EOFError:
            break

    return lines
    
def checkPassword(hash: str, password: str, hashIndex: int) -> bool:
    if len(hash) - hashIndex < len(password):
        return False
        
    pwIndex = 0
    for j in range(hashIndex, len(hash)):
        char = hash[j]
        for i in range(pwIndex, len(password)):
            pwChar = password[i]
            if char != pwChar:
                if i == len(password) - 1:
                    return False
                continue
                
            # swap
            if pwIndex != i:
                tmpChar = password[pwIndex]
                password[pwIndex] = password[i]
                password[i] = tmpChar
            
            # 
            pwIndex += 1
            break

    #print(hashIndex)        
    #print(password)
    return True
    
def checkHash(hash: str, password: str) -> str:
    if len(password) > len(hash):
        return "NO"
        
    hashIndex = 0;
    while hashIndex < len(hash):
        if checkPassword(hash, password, hashIndex) == True:
            return "YES"
        else:
            hashIndex += 1
            
    return "NO"
    
# main
inputs = getMultiLineInput()
count = int(inputs[0])
for i in range(0, count):
    password = list(inputs[2*i + 1])
    hash = inputs[2*i + 2]
    print(checkHash(hash, password))