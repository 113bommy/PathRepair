__author__ = 'zihaozhu'
from sys import stdin

s,f,i = map(int,stdin.readline().split())


if s==f:
    print("YES")
elif i==0:
    print ("NO")
elif (((f-s)%i==0) and ((((f-s)>0 and i>0) ) or ((f-s)<0 and i<0))):
    print ("YES")
else:
    print ("NO")


