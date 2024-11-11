from sys import stdin,stdout
from itertools import combinations
from collections import defaultdict,OrderedDict
import math
import heapq

def listIn():
    return list((map(int,stdin.readline().strip().split())))

def stringListIn():
    return([x for x in stdin.readline().split()])
    
def intIn():
    return (int(stdin.readline()))

def stringIn():
    return (stdin.readline().strip())

if __name__=="__main__":
    a,b,c=listIn()
    if a==b:
        print(a+b+2*c)
    elif a>b:
        print(2*(b+c)+1)
    else:
        print(2*(a+c)+1)
        