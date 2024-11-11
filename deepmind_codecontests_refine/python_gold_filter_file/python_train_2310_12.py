import math
import random
import sys
import collections


def In():
    return map(int, sys.stdin.readline().split())


input = sys.stdin.readline
#
# l = [1200,1300,1400,1500,1600,1700]
# print(random.choice(l))

def substrlesson():
    s = input().rstrip()
    minbefore = chr(123)
    for i in range(len(s)):
        minbefore = min(minbefore,s[i])
        if i and minbefore < s[i]:
            print('Ann')
        else:
            print('Mike')
substrlesson()
