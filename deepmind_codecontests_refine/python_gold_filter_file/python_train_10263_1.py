n = int(input())
strength = input()
strength = strength.split(' ')
strengthlist = []
for s in strength:
    strengthlist.append(int(s))

ssorted = strengthlist[:]
ssorted.sort()
support = 0
if (n <=2):
    support = 0
else:
    for i in range(0,n):
        sup1 = 0
        sup2 = 0
        if (ssorted[0]!=strengthlist[i]):
            sup1 = 1
        if (ssorted[-1]!=strengthlist[i]):
            sup2 = 1
        if (sup1+sup2==2):
            support = support+1
print(support)