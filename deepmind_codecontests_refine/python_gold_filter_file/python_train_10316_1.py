n = int(input())

a = list(input())
b = list(input())

p = int((n - 1) / 2)
n -= 1
ans = 0

for i in range(p+1):
    if i == n - i :
        if a[i] != b[i]:
            #print('yes')
            ans += 1
    else:
        #print(i)
        #print(n-i)
        isAA = False
        isBB = False
        isABi = False
        isABni = False
        isABini = False
        isABnii = False

        if a[i] == b[i]:
            isABi = True
        if a[n-i] ==b[n-i]:
            isABni = True
        if a[i] == b[n-i]:
            isABini = True
        if a[n-i] == b[i]:
            isABnii = True
        if a[i] == a[n-i]:
            isAA = True
        if b[i] == b[n-i]:
            isBB = True

        if isAA == False and isBB == False and isABi == False and isABni == False and isABini == False and isABnii == False:
            ans += 2
            #print('a')
        if isAA == False and isBB == False and isABi == False and isABni == False and isABini == True and isABnii == False:
            ans += 1
            #print('b')
        if isAA == False and isBB == False and isABi == False and isABni == False and isABini == False and isABnii == True:
            ans += 1
            #print('c')
        if isAA == False and isBB == False and isABi == True and isABni == False and isABini == False and isABnii == False:
            ans += 1
            #print('d')
        if isAA == False and isBB == False and isABi == False and isABni == True and isABini == False and isABnii == False:
            ans += 1
            #print('e')
        if isAA == True and isBB == False and isABi == False and isABni == False and isABini == False and isABnii == False:
            ans += 2
            #print('f')
        if isAA == False and isBB == True and isABi == False and isABni == False and isABini == False and isABnii == False:
            ans += 1
            #print('g')
        if isAA == True and isBB == False and isABi == True and isABni == False and isABini == False and isABnii == True:
            ans += 1
            #print('h')
        if isAA == False and isBB == True and isABi == True and isABni == False and isABini == True and isABnii == False:
            ans += 1
            #print('i')
        if isAA == False and isBB == True and isABi == False and isABni == True and isABini == False and isABnii == True:
            ans += 1
            #print('j')
        if isAA == True and isBB == False and isABi == False and isABni == True and isABini == True and isABnii == False:
            ans += 1
            #print('k')



print(ans)
