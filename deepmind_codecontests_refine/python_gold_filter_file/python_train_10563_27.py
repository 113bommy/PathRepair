
# -*- coding: utf-8 -*-
# @Date    : 2018-10-02 08:00:37
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

word_len, dict_len = read_ints()
dicts = {}
for _ in range(dict_len):
    one, two = read_strs()
    dicts[one] = one if len(one) <= len(two) else two
print(" ".join(dicts[x] for x in read_strs()))

