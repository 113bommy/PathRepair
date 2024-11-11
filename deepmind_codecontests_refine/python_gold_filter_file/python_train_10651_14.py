import sys

inf = float("inf")
# sys.setrecursionlimit(10000000)

# abc='abcdefghijklmnopqrstuvwxyz'
# abd={'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7, 'i': 8, 'j': 9, 'k': 10, 'l': 11, 'm': 12, 'n': 13, 'o': 14, 'p': 15, 'q': 16, 'r': 17, 's': 18, 't': 19, 'u': 20, 'v': 21, 'w': 22, 'x': 23, 'y': 24, 'z': 25}
mod, MOD = 1000000007, 998244353
# words = {1:'one',2:'two',3:'three',4:'four',5:'five',6:'six',7:'seven',8:'eight',9:'nine',10:'ten',11:'eleven',12:'twelve',13:'thirteen',14:'fourteen',15:'quarter',16:'sixteen',17:'seventeen',18:'eighteen',19:'nineteen',20:'twenty',21:'twenty one',22:'twenty two',23:'twenty three',24:'twenty four',25:'twenty five',26:'twenty six',27:'twenty seven',28:'twenty eight',29:'twenty nine',30:'half'}
# vow=['a','e','i','o','u']
# dx,dy=[0,1,0,-1],[1,0,-1,0]

# import random
# from collections import deque, Counter, OrderedDict,defaultdict
# from heapq import nsmallest, nlargest, heapify,heappop ,heappush, heapreplace
# from math import ceil,floor,log,sqrt,factorial,pi,gcd,degrees,atan2
# from bisect import bisect,bisect_left,bisect_right,insort,insort_left,insort_right

def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def get_ints(): return map(str, sys.stdin.readline().strip().split())
def input(): return sys.stdin.readline().strip()

# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

n = int(input())
max_girls, max_pizza,max_taxi = 0,0,0
taxi,pizza,girl = [],[],[]
for i in range(n):
    curr_girls,curr_pizza,curr_taxi = 0,0,0
    t,name = get_ints()
    t = int(t)
    for j in range(t):
        string = list(input())
        string.remove('-')
        string.remove('-')
        flag = 0
        for k in range(1,6):
            if string[k]>=string[k-1]:
                flag = 1
                break
        if flag==0:
            curr_pizza+=1
            continue
        flag = 0
        value = string[0]
        for k in range(1,6):
            if string[k]!=value:
                flag = 1
                break
        if flag==0:
            curr_taxi+=1
            continue
        curr_girls+=1
    if curr_taxi>max_taxi:
        max_taxi = curr_taxi
        taxi = [name]
    elif curr_taxi == max_taxi:
        max_taxi = curr_taxi
        taxi.append(name)
    if curr_girls>max_girls:
        max_girls = curr_girls
        girl = [name]
    elif curr_girls ==max_girls:
        max_girls = curr_girls
        girl.append(name)
    if curr_pizza>max_pizza:
        max_pizza = curr_pizza
        pizza = [name]
    elif curr_pizza ==max_pizza:
        max_pizza = curr_pizza
        pizza.append(name)

print(f'If you want to call a taxi, you should call: {", ".join(taxi)}.')
print(f'If you want to order a pizza, you should call: {", ".join(pizza)}.')
print(f'If you want to go to a cafe with a wonderful girl, you should call: {", ".join(girl)}.')

