#import math
#n, m = input().split()
#n = int (n)
#m = int (m)
#n, m, k= input().split()
#n = int (n)
#m = int (m)
#k = int (k)
#l = int(l)
#m = int(input())
#s = input()
##t = input()
#a = list(map(char, input().split()))
#a.append('.')
#print(l)
#a = list(map(int, input().split()))
#c = sorted(c)
#x1, y1, x2, y2 =map(int,input().split())
#n = int(input())
#f = []
#t = [0]*n
#f = [(int(s1[0]),s1[1]), (int(s2[0]),s2[1]), (int(s3[0]), s3[1])]
#f1 = sorted(t, key = lambda tup: tup[0])
x1, y1, x3, y3, x2, y2 = input().split()
x1 = int(x1)
x2 = int(x2)
x3 = int(x3)
y1 = int(y1)
y2 = int(y2)
y3 = int(y3)
mi =  x1*y1
if((x3-1) % x2 == 0 and (y3-1) % y2 == 0 and ((x3-1) / x2) %2 == ((y3-1)/ y2)%2):
    mi = min(mi, max((x3-1)/x2,(y3-1)/y2))  
if((x3-1) % x2 == 0 and (y1-y3) % y2 == 0 and ((x3-1) / x2) %2 == ((y1-y3)/ y2)%2):
    mi = min(mi, max((x3-1)/x2,(y1-y3)/y2))  
if((x1-x3) % x2 == 0 and (y3-1) % y2 == 0 and ((x1-x3) / x2) % 2 == ((y3-1)/ y2)%2):
    mi = min(mi, max((x1-x3)/x2,(y3-1)/y2)) 
if((x1-x3) % x2 == 0 and (y1-y3) % y2 == 0 and ((x1-x3) / x2)%2 == ((y1-y3)/ y2)%2):
    mi = min(mi, max((x1-x3)/x2,(y1-y3)/y2))   
if (mi == x1*y1 or ( (x2 >= x3 and x2 > x1-x3)  and mi != 0)or ((y2 >= y3 and y2 > y1-y3)  and mi != 0)):
    print("Poor Inna and pony!")
else:
    print(int(mi))
