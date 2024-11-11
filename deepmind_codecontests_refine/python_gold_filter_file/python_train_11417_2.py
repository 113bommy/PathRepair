def isPal(string):
    if string[::-1] == string:
        return True
    else:
        return False
    
string = input()
length = len(string)
max_len = len(string)
found = False

while(max_len!=0):
    for i in range(length - max_len + 1):
        temp = string[i:i+max_len]
        if not isPal(temp):
            found = True
            break
    if found:
        break
    else:
        max_len -= 1

print(max_len)