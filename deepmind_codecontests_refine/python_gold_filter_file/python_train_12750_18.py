import sys

def transformDigit(d):
    if d == '0' or d == '1':
        return []
    elif d == '2':
        return [2]
    elif d == '3' or d == '5' or d == '7':
        return [int(d)]
    elif d == '4':
        return [3, 2, 2]
    elif d == '6':
        return [5, 3]
    elif d == '8':
        return [7, 2, 2, 2]
    elif d == '9':
        return [7, 3, 3, 2]

if __name__ == "__main__":
    
    numLen = int(input(''))
    num = str(input(''))
    
    allDigits = []
    for d in num:
        currList = transformDigit(d)
        allDigits += currList
    
    allDigits.sort(reverse = True)
    
    for d in allDigits:
        sys.stdout.write(str(d))
    sys.stdout.write("\n")
    
    
    