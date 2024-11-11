
# -*- coding: utf-8 -*-
# @Date    : 2019-01-23 16:08:17
# @Author  : raj lath (oorja.halt@gmail.com)
# @Link    : link
# @Version : 1.0.0

from sys import stdin

max_val=int(10e12)
min_val=int(-10e12)

def read_int()     : return int(stdin.readline())
def read_ints()    : return [int(x) for x in stdin.readline().split()]
def read_str()     : return input()
def read_strs()    : return [x for x in stdin.readline().split()]

d = read_int()
n = read_int()
days = read_ints()[:-1]
print(sum([abs(x - d) for x in days]))