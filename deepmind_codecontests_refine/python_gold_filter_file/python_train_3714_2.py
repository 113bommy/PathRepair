# -*- coding: utf-8 -*-
"""
Created on Thu Mar 12 11:52:12 2020

@author: akprasad
"""

def get_n_digit_binary(n):
    if n == 1:
        return ['0', '1']
    smaller = get_n_digit_binary(n-1)
    return ['0' + s for s in smaller] + ['1' + s for s in smaller]


def get_all_n_digit_binary(n):
    if n == 1:
        return ['1']
    smaller = get_all_n_digit_binary(n-1)
    return smaller + ['1' + s for s in get_n_digit_binary(n-1)]


if __name__ == '__main__':
    MAX = 10
    n = int(input())
    ndb = [int(x) for x in get_all_n_digit_binary(MAX)]
    found = False
    for i in range(len(ndb)):
        if ndb[i] > n:
            print(i)
            found = True
            break
    if not found:
        print(len(ndb))