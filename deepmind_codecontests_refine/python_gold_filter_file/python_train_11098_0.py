
Input=lambda:map(str,input().split())

S, E = input().split()
n = int(input())
cw = ccw = True
l = ['^','>','v','<']
ind1 = l.index(S)
ind2 = l.index(E)
# cw
if ind1 <= ind2:
    if (n - (ind2 - ind1)) % 4 !=0:
        cw = False
else:
    if (n-((3 - ind1)+(ind2+1))) % 4 !=0:
        cw = False 
if cw == False:
    print("ccw")
    exit()
# ccw
if ind1 >= ind2:
    if (n - (ind1 - ind2)) % 4 !=0:
        ccw = False
else:
    if (n - (ind1+(4-ind2))) % 4 != 0:
        ccw = False
print("cw" if ccw == False else "undefined")
