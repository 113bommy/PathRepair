from sys import stdin, stdout
in1 = int(stdin.readline())
for i in range(in1):
    in2 = stdin.readline()
    in3 = stdin.readline()
    in3 = in3.split()
    l = len(set(in3))
    stdout.write(str(l)+'\n')
    
'''
in1 = int(input())
for i in range(in1):
    in2 = input()
    in3 = input().split()
    l = len(set(in3))
    print(l)
    '''
'''
from collections import Counter 
in1 = int(input())
for i in range(in1):
    in2 = input()
    in3 = input().split()
    print(len(Counter(in3).keys()))
    '''