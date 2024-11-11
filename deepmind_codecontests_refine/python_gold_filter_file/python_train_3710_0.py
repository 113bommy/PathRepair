# -*- coding: utf-8 -*-
"""
Created on Tue Dec 12 18:25:20 2017

@author: ms
"""

def main():
    h1,a1,c1 = [int(x) for x in input().split()]
    h2,a2 = [int(x) for x in input().split()]
    
    strike = 0
    heal = 0
    while(1):
        if (h1>a2 or a1>=h2):
            strike += 1
            h2 -= a1
            if (h2<=0):
                break
            else:
                h1 -= a2
        else:
            heal += 1
            h1 += c1
            h1 -= a2
            
    print(strike + heal)
    for j in range(heal):
        print('HEAL')
    for i in range(strike):
        print('STRIKE')
        
    
main()