#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Mar 17 22:08:22 2019

@author: killmonger
"""

import os
import sys
import math
import collections
import cmath
def mp():
    return map(int,input().split())
def inp():
    return input()
n = int(inp())
for i in range(n):
    a,b=mp()
    print(str(a)+" "+ str(a+a))