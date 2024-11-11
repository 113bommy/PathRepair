# -*- coding: utf-8 -*-
"""
Created on Tue Jun 30 20:17:56 2020

@author: ElAhwel
"""

dictionary = {1:'a',2:'b',3:'c',4:'d',5:'e',
              6:'f',7:'g',8:'h',9:'i',10:'j'
              ,11:'k',12:'l',13:'m',14:'n'
              ,15:'o',16:'p',17:'q',18:'r'
              ,19:'s',20:'t',21:'u',22:'v'
              ,23:'w',24:'x',25:'y',26:'z'}


n , distinct = list(map(int , input().split()))
count = 0
st=''
for i in range(distinct):
    st += dictionary[i+1]
st2=''
for _ in range(n):
    st2 += st[count]
    count +=1
    if count > distinct-1:
        count = 0
    
print(st2)