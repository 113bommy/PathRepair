#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Aug 21 15:40:31 2020

@author: suneelvarma
"""
from collections import Counter
# A function takes in a target and a list of numbers returns 
# how many pairs does that nums have whose sum is equal to 
# target given(no index should repeat twice)

def howmany(target,nums,freqs):
    onDemand = dict()
    total_pairs = 0
    
    for ind,num in enumerate(nums):
        #if num >= target: break
        if onDemand.get(num,None) == 'over': continue
        
        if num in onDemand:
            if num != target-num:
                total_pairs += min(freqs[num],freqs[target-num])
            elif num == target-num:
                total_pairs += freqs[num]//2
            onDemand[num] = onDemand[target-num] = 'over'
            
        else:
            onDemand[target-num] = ind
    
    return total_pairs



def pairs(nums,n):
    #if len(nums) == 1: return 0
    nums.sort()
    freqs = Counter(nums)
    srange = range(min(nums)*2, (max(nums)*2)+1)
    maxx_pairs = -1
    for target in srange:
        maxx_pairs =  max(howmany(target,nums,freqs), maxx_pairs)
    return maxx_pairs





if __name__ == "__main__":
    
    t = int(input())
    for _ in range(t):
        n = int(input())
        weits= list(map(int,input().split()))
        print(pairs(weits,n))
        
