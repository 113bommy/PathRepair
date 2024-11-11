n, k = [int(i) for i in input().split()]

strN = str(n)

removedDigits = 0

def floatInt(num):
    if num % 1 > 0:
        return float
    else:
        return int

if ( n / (10 ** k) ) < 1:
    
    lnStrN = len(strN)
    zeros  = strN.count("0")
    if zeros > 1:
        removed0 = zeros - 1
    else:
        removed0 = 0
        
    print(lnStrN - zeros + removed0)
        

else:
    while floatInt( n / (10 ** k) ) == float:
        inv = strN[::-1]
        for i in inv:
            if int(i) in [1,2,3,4,5,6,7,8,9]:
                inv = inv.replace(i ,"", True)
                removedDigits += 1
                strN = inv[::-1]
                if strN == "":
                    n = 0
                    break
                n = int(strN)
                break

    if len(strN) > 1 and n == 0:
        removedDigits += (len(strN)-1)

    print(removedDigits)
