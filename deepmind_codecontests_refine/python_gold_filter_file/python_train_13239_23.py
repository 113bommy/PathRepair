from math import log,pow
#a = [int(x) for x in input().strip().split()]
a = input().strip()
#print(len(a))
if len(a)==1:
    print('0')
elif int(a[1:])==0:
    print(int((len(a)) / 2))
else:
    print(int((len(a)-1)/2)+1)

