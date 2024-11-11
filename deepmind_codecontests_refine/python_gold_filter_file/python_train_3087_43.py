'''
class Car:
    def __init__(self, brand, model):
        self.brand = brand
        self.model = model

    def info(self,fuel,reducpersec,time,dist,remainingfuel):
        self.fuel=fuel
        self.reducpersec=reducpersec
        self.time=time
        self.dist=dist
        self.remainingfuel=remainingfuel




# Create some real monsters
fogthing = Car("Black", "1980")

# Check whether those monsters got different existence in memory or not
print('I am ' + str(fogthing.brand) + ' body and I\'m ' + fogthing.model+'\'s')

print('I also have ' + str(mournsnake.heads) + ' heads and I\'m ' + mournsnake.color)
print('I got ' + str(tangleface.heads) + ' heads and I\'m ' + tangleface.color)
'''

'''
import math
import cmath

print(math.pi)
print(cmath.sqrt(25))


f=open("/media/rayhan/CSE/My Codes/Rough/in.txt","r")
for i in f:
    a=i
    print(i.rstrip(),sep=' ',end=" ")
print()
f.close()


try:
    a=10
    b=4
    print(int(a)/int(b))
except ZeroDivisionError:
    print("You have to enter a non-zero divisor!!\n")

def add(x,y):
    #print(int().__doc__)
    return  x+y

print(add(5,6))



a=[2,1,3,4,5,6]
# n=int(input())
# a.append(n)
a[2]=10
# i=int(1)
n=len(a)
for i in range(1,n,1):
    print(a[int(i)-1])
    # print("{0} {1}".format(i,p))

'''

n=int(input())
s=input()
v=['a','e','i','o','u','y']

p=1
for i in range(0,n,1):
    if s[i] not in v:
        print(s[i],end='')
        p=1
    elif s[i] in v and p==1:
        print(s[i],end='')
        p = 0
    else:
        continue














