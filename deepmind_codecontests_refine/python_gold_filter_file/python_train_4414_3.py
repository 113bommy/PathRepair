# -*- coding: utf-8 -*-
"""
Created on Mon Feb 26 19:46:48 2018

@author: hp
"""
#two circle create one circle
def twoCirclesCreateOneCircle(x1,y1,r1,x2,y2,r2):
    return r2 * r2 - r1 * r1,2 * x2 * r1 * r1 - 2 * x1 * r2 * r2,\
          2 * y2 * r1 * r1 - 2 * y1 * r2 * r2,\
          r2 * r2 * (x1 * x1 + y1 * y1) - r1 * r1 * (x2 * x2 + y2 * y2)

#input circle,output center and round
def circleCenterRound(a,b,c,d):
    return - b / (2 * a),- c / (2 * a),\
         ((b * b + c * c - 4 * a * d)/(4 * a * a)) ** 0.5

#calcaute joint of two lines
def jointOfTwoLines(a1,b1,c1,a2,b2,c2):
    return (c2 * b1 - c1 * b2) / (a1 * b2 - a2 * b1),\
           (c2 * a1 - c1 * a2) / (b1 * a2 - b2 * a1)

#calcaute joint of a line and a circle
def jointOfLineAndCircle(a1,b1,c1,x1,y1,r):
    if (a1 * x1 + b1 * y1 + c1) ** 2 / (a1 ** 2 + b1 ** 2) > r ** 2:
        return False,False,False,False
    elif b1 != 0:
        a = 1 + a1 * a1 / (b1 * b1);
        b = -2 * x1 + 2 * a1 / b1 * (c1 / b1 + y1);
        c = x1 * x1 + (c1 / b1 + y1) ** 2 - r * r;
        x2 = (- b + (b ** 2 - 4 * a * c) ** 0.5) / (2 * a);
        x3 = (- b - (b ** 2 - 4 * a * c) ** 0.5) / (2 * a);
        y2 = - a1 * x2 / b1 - c1 / b1;
        y3 = - a1 * x3 / b1 - c1 / b1;
        return x2,y2,x3,y3
    else:
        x2 = - c1 / a1;
        x3 = - c1 / a1;
        y2 = y1 + (r ** 2 - (x2 - x1) ** 2) ** 0.5;
        y3 = y1 - (r ** 2 - (x3 - x1) ** 2) ** 0.5;
        return x2,y2,x3,y3
#caulcute joint of circle and circle
def jointOfCircles(x1,y1,r1,x2,y2,r2):
    a,b,c,d = jointOfLineAndCircle(2 * x2 -2 * x1,2 * y2 - 2 * y1,x1 * x1 + y1 * y1 - x2 * x2 - y2 * y2 + r2 ** 2 - r1 ** 2,x1,y1,r1)
    return a,b,c,d

def main():
    [x1,y1,r1] = [eval(x) for x in str.split(input())]
    [x2,y2,r2] = [eval(x) for x in str.split(input())]
    [x3,y3,r3] = [eval(x) for x in str.split(input())]

    a1,b1,c1,d1 = twoCirclesCreateOneCircle(x1,y1,r1,x2,y2,r2)
    a2,b2,c2,d2 = twoCirclesCreateOneCircle(x2,y2,r2,x3,y3,r3)
    
    #if two lines:
    if abs(a1) < 0.0001 and abs(a2) < 0.0001:
        x4,y4 = jointOfTwoLines(b1,c1,d1,b2,c2,d2);
        print(x4,y4)
    # if circle and line    
    if abs(a1) < 0.0001 and abs(a2) >= 0.0001:
        x4,y4,r4 = circleCenterRound(a2,b2,c2,d2)
        x5,y5,x6,y6 = jointOfLineAndCircle(b1,c1,d1,x4,y4,r4)
        if x5 == False:
            print()
        elif (x5 - x1) ** 2 + (y5 - y1) ** 2 < (x6 - x1) ** 2 + (y6 - y1) ** 2:
            print(x5,y5)
        else:
            print(x6,y6)
            
    if abs(a2) < 0.0001 and abs(a1) >= 0.0001:
        x4,y4,r4 = circleCenterRound(a1,b1,c1,d1)
        x5,y5,x6,y6 = jointOfLineAndCircle(b2,c2,d2,x4,y4,r4)
        if x5 == False:
            print()
        elif (x5 - x1) ** 2 + (y5 - y1) ** 2 < (x6 - x1) ** 2 + (y6 - y1) ** 2:
            print(x5,y5)
        else:
            print(x6,y6)    
    
    #if two circles
    if abs(a2) > 0.0001 and abs(a1) > 0.0001:
        x4,y4,r4 = circleCenterRound(a1,b1,c1,d1)
        x5,y5,r5 = circleCenterRound(a2,b2,c2,d2)
        x6,y6,x7,y7 = jointOfCircles(x4,y4,r4,x5,y5,r5)
        if x6 == False:
            print()
        elif (x6 - x1) ** 2 + (y6 - y1) ** 2 < (x7 - x1) ** 2 + (y7 - y1) ** 2:
            print(x6,y6)
        else:
            print(x7,y7)      
main()







