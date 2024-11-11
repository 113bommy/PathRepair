def check(s):
    sLen = len(s)
    if sLen > 16 or sLen <= 0:
        return False
    for i in range(sLen):
        temp = ord(s[i])
        if not (65 <= temp <= 90 or
                97 <= temp <= 122 or
                48 <= temp <= 57 or
                s[i] == '_'):
            return False
    return True


def check_host(hostName):
    hLen = len(hostName)
    if hLen > 32 or hLen == 0:
        return False
    '''
    tokens = hostName.split('.')
    for i in range(len(tokens)):
        if not check(tokens[i]):
            return False

    return True
    '''
    for item in hostName.split('.'):
        if not check(item):
            return False

    return True


''' while hLen-1:
     for i in range(hostName):
         if hostName[i] == '.':
             temp1 = check(hostName[:hostName.index('.')])
             hostName = hostName[hostName.index('.') + 1:]
             i = i - hostName.index('.') + 1
             return True
         elif hostName[i] != '.':
             firstHalf = hostName[:hLen//2]
             secHalf = hostName[hLen//2:]
             return check(firstHalf) and check(secHalf)
         else:
             return False
             '''

text = input()
isUser, isHost, isRes = False, False, False
if '@' in text:
    atInd = text.index('@')
    userName = text[:atInd]
    isUser = check(userName)
    '''
    hostName = ''
    if '/' in text:
        hostName = text[atInd+1:text.index('/')]
    else: 
        hostName = text[atInd+1:]
    '''
    hostName = text[atInd + 1:text.index('/')] if '/' in text else text[atInd + 1:]
    isHost = check_host(hostName)
    if '/' not in text:
        isRes = True
    else:
        res = text[text.index('/') + 1:]
        isRes = check(res)
'''
if isUser and isHost and isRes:
    print('YES')
else:
    print('NO')
'''
print('YES' if isUser and isHost and isRes else 'NO')
